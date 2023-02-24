#include "otioTranslator.h"
#include "utils.h"

MStatus OtioTranslator::reader(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    const MString filename = file.expandedFullName();
    const auto filepath = convertMStringToString(filename);
    MStatus status;

    MGlobal::displayInfo("Reading file: " + filename);

    // Load the timeline into memory
    otio::ErrorStatus errorStatus;
    const auto timeline = dynamic_cast<otio::Timeline*>(
        otio::Timeline::from_json_file(filepath, &errorStatus)
    );

    // Check for errors
    if (!timeline || otio::is_error(errorStatus)) {
        const auto errorMsg = "Error loading: " + filepath + " : "
            + otio::ErrorStatus::outcome_to_string(errorStatus.outcome)
            + ": " + errorStatus.details;
        MGlobal::displayError(convertStringToMString(errorMsg));

        return MStatus::kFailure;
    }

    if (timeline->video_tracks().size() == 0) {
        MGlobal::displayInfo("No video tracks");

        return MS::kSuccess;
    }

    MDGModifier fDGModifier;;
    int trackNo = 1;

    for (const auto& track : timeline->video_tracks()) {
        MObject seqObj = fDGModifier.createNode("sequencer", &status);
        MFnDependencyNode seqNode(seqObj, &status);
        const MString trackName = convertStringToMString(track->name());
        seqNode.setName(trackName);

        if (status != MS::kSuccess) {
            MGlobal::displayError("Error when creating sequence node: " + status.errorString());
        }

        for (const auto& clip : track->find_clips()) {
            MObject shotObj = fDGModifier.createNode("shot", &status);
            MFnDependencyNode shotNode(shotObj, &status);

            const auto clipName = convertStringToMString(clip->name());
            const otio::ImageSequenceReference* mediaRef = dynamic_cast<otio::ImageSequenceReference*>(clip->media_reference());
            const auto range = clip->source_range();
            const auto rate = range->start_time().rate();
            const auto duration = range->duration().value();
            const auto seqStartFrame = mediaRef->start_frame() / rate;
            const auto startFrame = range->start_time().value() / rate;
            const auto endFrame = (range->start_time().value() + range->duration().value()) / rate;
            shotNode.setName(clipName);
            shotNode.findPlug("shotName", true, &status).setValue(convertStringToMString(clip->name()));
            shotNode.findPlug("clipDuration", true, &status).setValue(duration);
            shotNode.findPlug("sequenceStartFrame", true, &status).setValue(seqStartFrame);
            shotNode.findPlug("startFrame", true, &status).setValue(startFrame);
            shotNode.findPlug("endFrame", true, &status).setValue(endFrame);
            shotNode.findPlug("track", true, &status).setValue(trackNo);

            if (status != MS::kSuccess) {
                MGlobal::displayError("Error when creating shot node: " + status.errorString());
            }
        }

        trackNo += 1;
    }

    // Apply changes to all dependency nodes.
    fDGModifier.doIt();

    return status;
}

MStatus OtioTranslator::writer(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    const MString fileName = file.expandedFullName();
    const auto filepath = convertMStringToString(fileName);

    otio::ErrorStatus errorStatus;
    auto name = convertMStringToString(file.resolvedName());
    std::stringstream ss(name);

    const int dotIndex = name.find(".");
    if (dotIndex != std::string::npos) {
        name = name.substr(0, dotIndex);
    }

    // Further documentation on OTIO timeline
    // https://opentimelineio.readthedocs.io/en/latest/tutorials/otio-timeline-structure.html
    const auto timeline = otio::SerializableObject::Retainer<otio::Timeline>(new otio::Timeline(name));

    // Check which objects are to be exported. Only 'export all' are allowed.
    if (MPxFileTranslator::kExportAccessMode != mode) return MStatus::kFailure;

    // Export all and if there is an error than return failure status.
    if (MStatus::kFailure == exportAll(timeline)) return MStatus::kFailure;

    // Write timeline to the desired file. Log error if error is occurred while
    // writing the file.
    if (!timeline.value->to_json_file(filepath, &errorStatus)) {
        const auto errorMsg = "Error writing to " + filepath + " : "
            + otio::ErrorStatus::outcome_to_string(errorStatus.outcome)
            + ": " + errorStatus.details;
        MGlobal::displayError(convertStringToMString(errorMsg));
        return MS::kFailure;
    };

    MGlobal::displayInfo("Export to " + fileName + " was successful!");

    return MS::kSuccess;
}

MStatus OtioTranslator::exportAll(const otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MGlobal::displayInfo("Exporting everything to a new file.");

    // Process and loop through all nodes in the dependency graph.
    MItDependencyNodes nodeIter;
    for (; !nodeIter.isDone(); nodeIter.next()) {
        MObject	node = nodeIter.thisNode();

        if (node.apiType() == MFn::kSequencer) processSequenceNode(node, timeline);
    }

    return MStatus::kSuccess;
}

MStatus OtioTranslator::processSequenceNode(MObject node, const otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MFnDependencyNode seqNode(node);
    MPlugArray plugs;
    seqNode.getConnections(plugs);

    // Create stack and track container for processing shot nodes.
    const auto stack = otio::SerializableObject::Retainer<otio::Stack>(new otio::Stack());
    timeline.value->set_tracks(stack);
    const auto track = otio::SerializableObject::Retainer<otio::Track>(
        new otio::Track(convertMStringToString(seqNode.name()))
    );

    // Process each dependency node connected to the sequence node.
    for (auto plug : plugs) {
        MPlugArray seqPlugs;
        plug.connectedTo(seqPlugs, true, false);

        for (auto seqPlug : seqPlugs) {
            MObject srcNode = seqPlug.node();

            if (srcNode.apiType() != MFn::kShot) continue;

            if (!processShotNode(srcNode, track) != MStatus::kSuccess) {
                MGlobal::displayError("Error processing shot node: " + seqPlug.name());
            }
        }
    }

    // Add stack with new clips.
    stack.value->append_child(track);

    return MStatus::kSuccess;
}

MStatus OtioTranslator::processShotNode(MObject node, const otio::SerializableObject::Retainer<otio::Track>& track) {
    MFnDependencyNode shotNode(node);
    MStatus status;
    MTime startFrame;
    MTime endFrame;
    MTime seqStartFrame;

    shotNode.findPlug("sequenceStartFrame", true, &status).getValue(seqStartFrame);
    shotNode.findPlug("startFrame", true, &status).getValue(startFrame);
    shotNode.findPlug("endFrame", true, &status).getValue(endFrame);
    int fStartFrame = (int) startFrame.as(MTime::uiUnit());
    int fEndFrame = (int) endFrame.as(MTime::uiUnit());
    int fSeqStartFrame = (int) seqStartFrame.as(MTime::uiUnit());

    // Run a MEL command to get the time. Once we get the time we tie it to a framerate.
    // This framerate is need when creating otio clips
    MString queriedTime;
    MGlobal::executeCommand("currentUnit -query -time", queriedTime);
    const auto frameRate = OtioTranslator::frameRate.at(convertMStringToString(queriedTime));
    const auto mediaRef = new otio::ImageSequenceReference(
        "",
        "",
        "",
        fSeqStartFrame
    );
    const auto clip = otio::SerializableObject::Retainer<otio::Clip>(
        new otio::Clip(
            convertMStringToString(shotNode.name()),
            mediaRef,
            opentime::TimeRange(
                opentime::RationalTime(fStartFrame, frameRate),
                opentime::RationalTime(fEndFrame - fStartFrame, frameRate)
            )
        )
    );

    // Add newly created clip to the track.
    track.value->append_child(clip);

    return status;
}

MPxFileTranslator::MFileKind OtioTranslator::identifyFile(const MFileObject& fileName, const char* buffer, short size) const {
    const auto fileNameStr = convertMStringToString(fileName.resolvedName());
    const auto extention = "." + convertMStringToString(defaultExtension());

    return fileNameStr.find(extention) != std::string::npos
        ? kIsMyFileType
        : kNotMyFileType;
}
