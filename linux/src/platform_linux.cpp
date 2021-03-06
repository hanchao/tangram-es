#ifdef PLATFORM_LINUX

#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <string>

#include "platform.h"
#include "gl.h"

static bool s_isContinuousRendering = false;

void logMsg(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void requestRender() {
    
    glfwPostEmptyEvent();
    
}

void setContinuousRendering(bool _isContinuous) {
    
    s_isContinuousRendering = _isContinuous;
    
}

bool isContinuousRendering() {
    
    return s_isContinuousRendering;
    
}

std::string stringFromResource(const char* _path) {
    std::string into;

    std::ifstream file;
    std::string buffer;

    file.open(_path);
    if(!file.is_open()) {
        logMsg("Failed to open file at path: %s\n", _path);
        return std::string();
    }

    while(!file.eof()) {
        getline(file, buffer);
        into += buffer + "\n";
    }

    file.close();
    return into;
}

unsigned char* bytesFromResource(const char* _path, unsigned int* _size) {
    std::ifstream resource(_path, std::ifstream::ate | std::ifstream::binary);

    if(!resource.is_open()) {
        logMsg("Failed to read file at path: %s\n", _path);
        *_size = 0;
        return nullptr;
    }

    *_size = resource.tellg();

    resource.seekg(std::ifstream::beg);

    char* cdata = (char*) malloc(sizeof(char) * (*_size));

    resource.read(cdata, *_size);
    resource.close();

    return reinterpret_cast<unsigned char *>(cdata);
}

#endif
