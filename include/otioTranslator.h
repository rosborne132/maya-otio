#ifndef OTIO_TRANSLATOR_H
#define OTIO_TRANSLATOR_H

#include <fstream>
#include <ios>
#include <sstream>

#include <maya/MStatus.h>
#include <maya/MString.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MGlobal.h>
#include <maya/MObject.h>
#include <maya/MFnClip.h>
#include <maya/MPlug.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MTime.h>
#include <maya/MPlugArray.h>
#include <maya/MPlug.h>

#include <opentimelineio/clip.h>
#include <opentimelineio/timeline.h>
#include <opentimelineio/track.h>
#include <opentime/timeRange.h>

namespace otio = opentimelineio::OPENTIMELINEIO_VERSION;

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
        // called when a write operation is performed on the parent file. This use is for users who wish
        // to implement a custom file referencing system.
        // For this example, we will return false as we will use Maya's file referencing system.
        bool haveReferenceMethod() const override { return false; }

        // If this method returns true, it means we support namespaces.
        bool haveNamespaceSupport() const override { return true; }

        // This method is used by Maya to create instances of the translator.
        static void* creator();

        // This returns the default extension ".otio" in this case.
        // Whenever Maya needs to know the preferred extension of this file format,
        // it calls this method. For example, if the user tries to save a file called
        // "test" using the Save As dialog, Maya will call this method and actually
        // save it as "test.otio". Note that the period should *not* be included in
        // the extension.
        MString defaultExtension() const override { return "otio"; };

        // If this method returns true it means that the translator can handle opening files
        // as well as importing them.
        // If the method returns false then only imports are handled. The difference between
        // an open and an import is that the scene is cleared(e.g. 'file -new') prior to an
        // open, which may affect the behaviour of the translator.
        bool canBeOpened() const override { return true; }

        // Maya will call this method to determine if our translator
        // is capable of handling this file.
        MFileKind identifyFile(const MFileObject& fileName, const char* buffer, short size) const override;

        // This method is called by maya when import or open is called.
        MStatus reader(const MFileObject& file, const MString& optionsString, MPxFileTranslator::FileAccessMode mode) override;

        // This method is called by maya when export or save is called.
        MStatus writer(const MFileObject& file, const MString& optionsString, MPxFileTranslator::FileAccessMode mode) override;

    private:
        // This helper method exports everything in the scene.
        MStatus exportAll(otio::SerializableObject::Retainer<otio::Timeline>& timeline);

        // This helper method is for processing shot nodes.
        MStatus processShotNode(MObject node, otio::SerializableObject::Retainer<otio::Track>& track);

        // This helper method is for processing sequence nodes.
        MStatus processSequenceNode(MObject node, otio::SerializableObject::Retainer<otio::Timeline>& timeline);
};

#endif