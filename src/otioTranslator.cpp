#include "otioTranslator.h"

// Create one instance of the OtioTranslator
void* OtioTranslator::creator() { return new OtioTranslator(); }

// Initialize with magic string
// TODO: check, but otio might not need this method because of the file
// format
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
    const MString fileName = file.expandedFullName();
    MStatus status = MS::kSuccess;

    MGlobal::displayInfo("Writing to file " + fileName);

    return status;
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
