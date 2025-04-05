#include "OsSpecificConfig.hpp"


std::string OsSpecificConfig::getPathSeparator() {
    #ifdef _WIN32
        return "\\";
    #else
        return "/";
    #endif
}
