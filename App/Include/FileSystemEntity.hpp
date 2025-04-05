#ifndef _FILESYSTEMENTITY_HPP_
#define _FILESYSTEMENTITY_HPP_

#include <string>
#include <stdexcept>
#include "Utils.hpp"
#include "OsSpecificConfig.hpp"


class FileSystemEntity {
public:
    FileSystemEntity() = default;
    FileSystemEntity(const std::string &path, const std::string &name);
    std::string getFullPath() const;
    void move(const std::string &newPath);
protected:
    std::string _path, _name;
};


#endif // _FILESYSTEMENTITY_HPP_
