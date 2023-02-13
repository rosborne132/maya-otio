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

    // TODO: Update based on the otio file format
	// writeHeader(newFile);

	// Check which objects are to be exported, and invoke the corresponding
	// methods; only 'export all' and 'export selection' are allowed
	if (MPxFileTranslator::kExportAccessMode == mode) {
		if (MStatus::kFailure == exportAll(timeline)) {
			return MStatus::kFailure;
		}
	} else if (MPxFileTranslator::kExportActiveAccessMode == mode) {
		if (MStatus::kFailure == exportSelection(timeline)) {
			return MStatus::kFailure;
		}
	} else {
		return MStatus::kFailure;
	}

    // TODO: Update based on the otio file format
	// writeFooter(newFile);
	// newFile.flush();
	// newFile.close();

    if(!timeline.value->to_json_file(filepath, &errorStatus)) {
        auto errorMsg = "Error writing to " + filepath + " : "
            + otio::ErrorStatus::outcome_to_string(errorStatus.outcome)
            + ": " + errorStatus.details;
        MGlobal::displayError(convertStringToMString(errorMsg));
        return MS::kFailure;
    };

	MGlobal::displayInfo("Export to " + fileName + " successful!");
	return MS::kSuccess;
}

MStatus OtioTranslator::exportAll(otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MGlobal::displayInfo("Exporting everything to new file.");

    MStatus status;
    MItDag dagIterator(MItDag::kDepthFirst, MFn::kInvalid, &status);

    if (MStatus::kFailure == status) {
		MGlobal::displayError("Failure in DAG iterator setup");
		return MStatus::kFailure;
	}

    for (dagIterator.next(); !dagIterator.isDone(); dagIterator.next()) {
        MObject currentNode = dagIterator.currentItem();
        processNodeByType(currentNode, timeline);
    }

    return MStatus::kSuccess;
}

MStatus OtioTranslator::exportSelection(otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MGlobal::displayInfo("Exporting selected to new file.");

    MSelectionList selection;
    MGlobal::getActiveSelectionList(selection);
    MItSelectionList selIterator(selection, MFn::kDagNode);

    // Loop through all selected nodes and process them accordingly
    for (selIterator.next(); !selIterator.isDone(); selIterator.next()) {
        MObject currentNode;
        selIterator.getDependNode(currentNode);
        processNodeByType(currentNode, timeline);
    }

    return MStatus::kSuccess;
}

MStatus OtioTranslator::processNodeByType(MObject currentNode, otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    switch (currentNode.apiType()) {
        case MFn::kCamera:
            return processCameraNode(currentNode, timeline);
        default:
            return MStatus::kSuccess;
    }
}

MStatus OtioTranslator::processCameraNode(MObject currentNode, otio::SerializableObject::Retainer<otio::Timeline>& timeline) {
    MGlobal::displayInfo("Processing camera node.");

    MStatus status;
    MFnCamera camNode(currentNode, &status);

    if (status != MS::kSuccess) return MStatus::kFailure;

    MGlobal::displayInfo("camNode.name(): " + camNode.name());

    // TODO: Continue processing with all cameras

    return MStatus::kSuccess;
}

// Whenever Maya needs to know the preferred extension of this file format,
// it calls this method. For example, if the user tries to save a file called
// "test" using the Save As dialog, Maya will call this method and actually
// save it as "test.otio". Note that the period should *not* be included in
// the extension.
MString OtioTranslator::defaultExtension() const { return "otio"; }

// This method is pretty simple, maya will call this function
// to make sure it is really a file from our translator.
MPxFileTranslator::MFileKind OtioTranslator::identifyFile(const MFileObject& fileName, const char* buffer, short size) const {
    std::string fileNameStr = convertMStringToString(fileName.resolvedName());
    std::string extention = "." + convertMStringToString(defaultExtension());

    return fileNameStr.find(extention) != std::string::npos
        ? kIsMyFileType
        : kNotMyFileType;
}

