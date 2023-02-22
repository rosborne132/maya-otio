#pragma once

#include <fstream>
#include <ios>
#include <sstream>
#include <unordered_map>
#include <string>

#include <maya/MDGModifier.h>
#include <maya/MFnClip.h>
#include <maya/MGlobal.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MObject.h>
#include <maya/MPlug.h>
#include <maya/MPlug.h>
#include <maya/MPlugArray.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MStatus.h>
#include <maya/MString.h>
#include <maya/MTime.h>

#include <opentime/timeRange.h>
#include <opentimelineio/clip.h>
#include <opentimelineio/timeline.h>
#include <opentimelineio/track.h>

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
        static void* creator() { return new OtioTranslator(); }

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
        MStatus exportAll(const otio::SerializableObject::Retainer<otio::Timeline>& timeline);

        // This helper method is for processing shot nodes.
        MStatus processShotNode(MObject node, const otio::SerializableObject::Retainer<otio::Track>& track);

        // This helper method is for processing sequence nodes.
        MStatus processSequenceNode(MObject node, const otio::SerializableObject::Retainer<otio::Timeline>& timeline);

        const std::unordered_map<std::string, int> frameRate {
            {"2fps", 2},
            {"3fps", 3},
            {"4fps", 4},
            {"5fps", 5},
            {"6fps", 6},
            {"8fps", 8},
            {"10fps", 10},
            {"12fps", 12},
            {"16fps", 16},
            {"20fps", 20},
            {"23.976fps", 23.976},
            {"29.97fps", 29.97},
            {"29.97df", 29.97},
            {"40fps", 40},
            {"47.952fps", 47.952},
            {"59.94fps", 59.94},
            {"75fps", 75},
            {"80fps", 80},
            {"90fps", 90},
            {"100fps", 100},
            {"120fps", 120},
            {"125fps", 125},
            {"150fps", 150},
            {"200fps", 200},
            {"240fps", 240},
            {"250fps", 250},
            {"300fps", 300},
            {"375fps", 375},
            {"400fps", 400},
            {"500fps", 500},
            {"600fps", 600},
            {"750fps", 750},
            {"1200fps", 1200},
            {"1500fps", 1500},
            {"2000fps", 2000},
            {"3000fps", 3000},
            {"6000fps", 6000},
            {"44100fps", 44100},
            {"48000fps", 48000},
            {"game", 15},
            {"film", 24},
            {"pal", 25},
            {"ntsc", 30},
            {"show", 48},
            {"palf", 50},
            {"ntscf", 60}
        };
};
