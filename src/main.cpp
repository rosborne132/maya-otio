#include <stdio.h>
#include <maya/MFnPlugin.h>
#include <maya/MIOStream.h>

#include "otioTranslator.h"

MStatus initializePlugin(MObject obj) {
    MFnPlugin plugin(obj, "Autodesk", "1.0", "Any");
    MStatus status = plugin.registerFileTranslator("otio", "", OtioTranslator::creator, "", "option1=1", true);

    if (!status) {
        status.perror("registerFileTranslator");
    }

    return status;
}

MStatus uninitializePlugin(MObject obj) {
    MFnPlugin plugin(obj);
    MStatus status = plugin.deregisterFileTranslator("otio");

    if (!status) {
        status.perror("deregisterFileTranslator");
    }

    return status;
}
