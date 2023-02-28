#pragma once

#include <sstream>
#include <string>

#include <maya/MString.h>

MString convertStringToMString(std::string str) {
    const char* char_array = str.c_str();
    return MString(char_array);
}

std::string convertMStringToString(MString str) {
    const char* charStr = str.asChar();
    return std::string(charStr);
}

std::string getFileNameWithoutExtention(const MFileObject file) {
    auto name = convertMStringToString(file.resolvedName());
    std::stringstream ss(name);
    const int dotIndex = name.find(".");

    if (dotIndex != std::string::npos) {
        name = name.substr(0, dotIndex);
    }

    return name;
}

std::string cleanupName(std::string name) {
    std::stringstream ss(name);
    const int dotIndex = name.find(":");

    if (dotIndex != std::string::npos) {
        name = name.substr(dotIndex + 1, name.size());
    }

    return name;
}