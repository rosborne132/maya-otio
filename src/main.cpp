#include <stdio.h>
#include <maya/MString.h>
#include <maya/MFnPlugin.h>
#include <maya/MIOStream.h>

#include "otioTranslator.h"

MStatus initializePlugin(MObject obj) {
    MStatus status;
    MFnPlugin plugin(obj, "Autodesk", "1.0", "Any");

    status =  plugin.registerFileTranslator("otio", "", OtioTranslator::creator, "", "option1=1", true);

    if (!status) {
        status.perror("registerFileTranslator");

        return status;
    }

    return status;
}

MStatus uninitializePlugin(MObject obj) {
    MStatus status;
    MFnPlugin plugin(obj);

    status = plugin.deregisterFileTranslator("otio");

    if (!status) {
        status.perror("deregisterFileTranslator");

        return status;
    }

    return status;
}
