#ifndef _OSSPECIFICCONFIG_HPP_
#define _OSSPECIFICCONFIG_HPP_

#include <string>


class OsSpecificConfig {
public:
    static std::string getPathSeparator();
    static std::string getHomeDirectory();
};


#endif // _OSSPECIFICCONFIG_HPP_
