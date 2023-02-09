#ifndef OTIO_TRANSLATOR_H
#define OTIO_TRANSLATOR_H

#include <maya/MStatus.h>
#include <maya/MString.h>
#include <maya/MVector.h>
#include <maya/MStringArray.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MGlobal.h>
#include <maya/MItDag.h>
#include <maya/MObject.h>
#include <maya/MPlug.h>
#include <maya/MItSelectionList.h>
#include <maya/MSelectionList.h>
#include <maya/MFileIO.h>
#include <maya/MFnTransform.h>
#include <maya/MFnCamera.h>
#include <maya/MNamespace.h>

#include <opentimelineio/clip.h>

#include <fstream>
#include <iostream>
#include <ios>

// TODO: Check if we need to update these comments
class OtioTranslator : public MPxFileTranslator {
    public:
        OtioTranslator() {};
        ~OtioTranslator() override {};

        // This tells maya that the translator can read files.
        // Basically, you can import or load with your translator.
        bool haveReadMethod() const override { return true; }

        // This tells maya that the translator can write files.
        // Basically, you can export or save with your translator.
        bool haveWriteMethod() const override { return true; }

        // If this method returns true, and the otio file is referenced in a scene, the write method will be
        // called when a write operation is performed on the parent file.  This use is for users who wish
        // to implement a custom file referencing system.
        // For this example, we will return false as we will use Maya's file referencing system.
        bool haveReferenceMethod() const override { return false; }

        // If this method returns true, it means we support namespaces.
        bool haveNamespaceSupport() const override { return true; }

        // This method is used by Maya to create instances of the translator.
        static void* creator();

        // This returns the default extension ".otio" in this case.
        MString defaultExtension() const override;

        // If this method returns true it means that the translator can handle opening files
        // as well as importing them.
        // If the method returns false then only imports are handled. The difference between
        // an open and an import is that the scene is cleared(e.g. 'file -new') prior to an
        // open, which may affect the behaviour of the translator.
        bool canBeOpened() const override { return true; }

        // Maya will call this method to determine if our translator
        // is capable of handling this file.
        MFileKind identifyFile(const MFileObject& fileName, const char* buffer, short size) const override;

        // This function is called by maya when import or open is called.
        MStatus reader(const MFileObject& file, const MString& optionsString, MPxFileTranslator::FileAccessMode mode) override;

        // This function is called by maya when export or save is called.
        MStatus writer(const MFileObject& file, const MString& optionsString, MPxFileTranslator::FileAccessMode mode) override;

    private:
        // TODO: check if we still need this after adding the otio lib
        // The magic string to verify it's a OTIO file simply "<OTIO>"
        static MString const magic;
};

#endif