#include "otioTranslator.h"

// Create one instance of the OtioTranslator
void* OtioTranslator::creator() { return new OtioTranslator(); }

// Initialize with magic string
// TODO: check, but otio might not need this method because of the file format
MString const OtioTranslator::magic("<OTIO>");

// TODO: Add function comments
MStatus OtioTranslator::reader(const MFileObject& file, const MString& options, MPxFileTranslator::FileAccessMode mode) {
    // TODO: Add implementation

    const MString fileName = file.expandedFullName();
    MStatus status = MS::kSuccess;

    MGlobal::displayInfo("Reading file " + fileName);

    return status;
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

        // TODO: Currently we can only grab one at a time
        // Other createNodes include:
        // camera
        // transforms
        // shot
        // sequencer
        // script
        // lightLinker
        // displayLayerManager
        // renderLayerManager
        // renderLayer

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

//This method is pretty simple, maya will call this function
//to make sure it is really a file from our translator.
//To make sure, we have a little magic number and we verify against it.
// TODO: check if comment is still true for our file format
MPxFileTranslator::MFileKind OtioTranslator::identifyFile (const MFileObject& fileName, const char* buffer, short size) const {
    // TODO: Add implementation
    // TODO: Update comments
    // Check the buffer for the "OTIO" magic number, the
    // string "<OTIO>\n"

    MFileKind rval = kNotMyFileType;

    if ((size >= (short)magic.length()) &&
        (0 == strncmp(buffer, magic.asChar(), magic.length())))
    {
        rval = kIsMyFileType;
    }
    return rval;
}
