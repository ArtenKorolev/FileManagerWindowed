#include "OsSpecificConfig.hpp"


std::string OsSpecificConfig::getPathSeparator() {
#ifdef _WIN32
    return "\\";
#else
    return "/";
#endif
}

std::string OsSpecificConfig::getHomeDirectory() {
#ifdef _WIN32
    return "C:\\";
#else
    return "/";
#endif
}
