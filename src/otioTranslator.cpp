#include "otioTranslator.h"
#include "utils.h"

// Create one instance of the OtioTranslator
void* OtioTranslator::creator() { return new OtioTranslator(); }

MStatus OtioTranslator::reader(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    const MString filename = file.expandedFullName();
    auto filepath = convertMStringToString(filename);

    MGlobal::displayInfo("Reading file: " + filename);

    // Load the timeline into memory
    otio::ErrorStatus errorStatus;
    auto timeline = dynamic_cast<otio::Timeline*>(
        otio::Timeline::from_json_file(filepath, &errorStatus)
    );

    // Check for errors
    if (!timeline || otio::is_error(errorStatus)) {
        auto errorMsg = "Error loading: " + filepath + " : "
            + otio::ErrorStatus::outcome_to_string(errorStatus.outcome)
            + ": " + errorStatus.details;
        MGlobal::displayError(convertStringToMString(errorMsg));

        return MStatus::kFailure;
    }

    // Display information about what was loaded
    MGlobal::displayInfo(convertStringToMString("Loaded OTIO file: " + filepath));
    MGlobal::displayInfo(convertStringToMString("Timeline name: " + timeline->name()));
    MGlobal::displayInfo(convertStringToMString("Timeline duration: " + timeline->duration().to_timecode()));

    if (timeline->video_tracks().size() == 0) {
        MGlobal::displayInfo("No video tracks");
    } else {
        for (const auto& track : timeline->video_tracks()) {
            MGlobal::displayInfo(convertStringToMString("Track: " + track->name()));
            MGlobal::displayInfo(convertStringToMString("Kind: " + track->kind()));
            MGlobal::displayInfo(convertStringToMString("Duration: " + track->duration().to_timecode()));

            // TODO: Do something with the track data
        }
    }

    MGlobal::displayInfo("All Clips: ");
    for (const auto& clip : timeline->find_clips()) {
        MGlobal::displayInfo(convertStringToMString("Clip: " + clip->name()));
        MGlobal::displayInfo(convertStringToMString("Duration: " + clip->duration().to_timecode()));

        // TODO: Do something with the clip data
    }

    return MS::kSuccess;
}

MStatus OtioTranslator::writer(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    const MString fileName = file.expandedFullName();
    const std::string filepath = convertMStringToString(fileName);

    otio::ErrorStatus errorStatus;
    std::string name = convertMStringToString(file.resolvedName());
    std::stringstream ss(name);

    int dotIndex = name.find(".");
    if (dotIndex != std::string::npos) {
        name = name.substr(0, dotIndex);
    }

    // Good track doc https://opentimelineio.readthedocs.io/en/latest/tutorials/otio-timeline-structure.html
    auto timeline = otio::SerializableObject::Retainer<otio::Timeline>(new otio::Timeline(name));

	// Check which objects are to be exported, and invoke the corresponding methods.
    // Only 'export all' are allowed.
	if (MPxFileTranslator::kExportAccessMode != mode) return MStatus::kFailure;

    if (MStatus::kFailure == exportAll(timeline)) return MStatus::kFailure;

    if(!timeline.value->to_json_file(filepath, &errorStatus)) {
        auto errorMsg = "Error writing to " + filepath + " : "
            + otio::ErrorStatus::outcome_to_string(errorStatus.outcome)
            + ": " + errorStatus.details;
        MGlobal::displayError(convertStringToMString(errorMsg));
        return MS::kFailure;
    };

	MGlobal::displayInfo("Export to " + fileName + " was successful!");
	return MS::kSuccess;
}

MStatus OtioTranslator::exportAll(otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MGlobal::displayInfo("Exporting everything to a new file.");

    MStatus status;

    // Process and loop through all nodes in the dependency graph.
	MItDependencyNodes nodeIter;
    for (; !nodeIter.isDone(); nodeIter.next()) {
		MObject	node = nodeIter.thisNode();

        if (node.apiType() == MFn::kSequencer) {
            processSequenceNode(node, timeline);
        }
    }

    return MStatus::kSuccess;
}

MStatus OtioTranslator::processSequenceNode(MObject node, otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MFnDependencyNode nodeFn(node);
    MPlugArray plugs;
    auto plugArray = nodeFn.getConnections(plugs);

    // Create stack and track container for processing shot nodes.
    auto stack = otio::SerializableObject::Retainer<otio::Stack>(new otio::Stack());
    timeline.value->set_tracks(stack);
    auto track = otio::SerializableObject::Retainer<otio::Track>(
        new otio::Track(convertMStringToString(nodeFn.name()))
    );

    // Process each dependency node connected to the sequence node.
    for (auto plug : plugs) {
        MPlugArray	srcPlugs;
        plug.connectedTo(srcPlugs, true, false);

        for (auto srcPlug : srcPlugs) {
            MObject	srcNode = srcPlug.node();

            if (srcNode.apiType() != MFn::kShot) continue;

            if (!processShotNode(srcNode, track) != MStatus::kSuccess) {
                MGlobal::displayError("Error processing shot node: " + srcPlug.name());
            }
        }
    }

    // Add stack with new clips.
    stack.value->append_child(track);

    return MStatus::kSuccess;
}

MStatus OtioTranslator::processShotNode(MObject node, otio::SerializableObject::Retainer<otio::Track>& track) {
    MFnDependencyNode shotNode(node);
    MStatus status;
    MTime startFrame;
    MTime endFrame;

    MGlobal::displayInfo("Processing shot node: " + shotNode.name());

    shotNode.findPlug("startFrame", true, &status).getValue(startFrame);
    shotNode.findPlug("endFrame", true, &status).getValue(endFrame);
    int fStartFrame = (int) startFrame.as(MTime::uiUnit());
    int fEndFrame = (int) endFrame.as(MTime::uiUnit());

    // TODO: See if there is a media reference that we can attach to the clip.

    // TODO: Get real rate
    int rate = 10;

    auto clip = otio::SerializableObject::Retainer<otio::Clip>(
        new otio::Clip(
            convertMStringToString(shotNode.name()),
            nullptr,
            opentime::TimeRange(
                opentime::RationalTime(fStartFrame, rate),
                opentime::RationalTime(fEndFrame - fStartFrame, rate)
            )
        )
    );

    track.value->append_child(clip);

    return status;
}

// This method is pretty simple, maya will call this function
// to make sure it is really a file from our translator.
MPxFileTranslator::MFileKind OtioTranslator::identifyFile(const MFileObject& fileName, const char* buffer, short size) const {
    std::string fileNameStr = convertMStringToString(fileName.resolvedName());
    std::string extention = "." + convertMStringToString(defaultExtension());

    return fileNameStr.find(extention) != std::string::npos
        ? kIsMyFileType
        : kNotMyFileType;
}
