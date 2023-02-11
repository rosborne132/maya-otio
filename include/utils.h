#ifndef UTILS_H
#define UTILS_H

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

#endif