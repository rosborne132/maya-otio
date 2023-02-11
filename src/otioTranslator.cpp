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

// TODO: Add function comments
MStatus OtioTranslator::writer(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    // TODO: Add implementation
    MStatus status;
    const MString fileName = file.expandedFullName();
    bool showPositions = false;
    unsigned int i;

    std::ofstream newFile(fileName.asChar(), std::ios::out);
	if (!newFile) {
		MGlobal::displayError(fileName + ": could not be opened for reading");
		return MS::kFailure;
	}
	newFile.setf(std::ios::unitbuf);

	if (options.length() > 0) {
        // Start parsing.
        MStringArray optionList;
        MStringArray theOption;
        options.split(';', optionList);    // break out all the options.

        for(i = 0; i < optionList.length(); ++i){
            theOption.clear();
            MGlobal::displayInfo("Current option: " + optionList[i]);
            optionList[i].split('=', theOption);
            if (theOption[0] == MString("showPositions") && theOption.length() > 1) {
                showPositions = theOption[1].asInt() > 0;
            }
        }
    }

    // TODO: Remove later
    // output our magic number
    newFile << "<OTIO>\n";

    MItDag dagIterator(MItDag::kBreadthFirst, MFn::kInvalid, &status);

    if (!status) {
        status.perror("Failure in DAG iterator setup");
        return MS::kFailure;
    }

    MSelectionList selection;
    MGlobal::getActiveSelectionList(selection);
    MItSelectionList selIterator(selection, MFn::kDagNode);

    bool done = false;
    while (true) {
        MObject currentNode;
        switch (mode) {
            case MPxFileTranslator::kSaveAccessMode:
            case MPxFileTranslator::kExportAccessMode:
                if (dagIterator.isDone())
                    done = true;
                else {
                    currentNode = dagIterator.currentItem();
                    dagIterator.next();
                }
                break;
            case MPxFileTranslator::kExportActiveAccessMode:
                if (selIterator.isDone())
                    done = true;
                else {
                    selIterator.getDependNode(currentNode);
                    selIterator.next();
                }
                break;
            default:
                std::cerr << "Unrecognized write mode: " << mode << std::endl;
                break;
        }

        if (done) break;

        // Currently we can only grab one at a time
        // We only care about nodes that are transforms
        MFnTransform dagNode(currentNode, &status);
        // MFnCamera camNode(currentNode, &status);
        if (status == MS::kSuccess) {
            MString nodeNameNoNamespace = MNamespace::stripNamespaceFromName(dagNode.name());
            // MGlobal::displayInfo("camNode.name(): " + camNode.name());
            MGlobal::displayInfo("dagNode.name(): " + dagNode.name());
            MGlobal::displayInfo("nodeNameNoNamespace: " + nodeNameNoNamespace);
            // Continue to process the dagNode as we see fit.
            // For more information on the dagNode, reference MFnTransform.h
        }
    }

    newFile.close();

	MGlobal::displayInfo("Export to " + fileName + " successful!");

	return MS::kSuccess;
}

// Whenever Maya needs to know the preferred extension of this file format,
// it calls this method. For example, if the user tries to save a file called
// "test" using the Save As dialog, Maya will call this method and actually
// save it as "test.otio". Note that the period should *not* be included in
// the extension.
MString OtioTranslator::defaultExtension() const { return "otio"; }

// This method is pretty simple, maya will call this function
// to make sure it is really a file from our translator.
MPxFileTranslator::MFileKind OtioTranslator::identifyFile (const MFileObject& fileName, const char* buffer, short size) const {
    std::string fileNameStr = convertMStringToString(fileName.resolvedName());
    std::string extention = "." + convertMStringToString(defaultExtension());

    return fileNameStr.find(extention) != std::string::npos
        ? kIsMyFileType
        : kNotMyFileType;
}
