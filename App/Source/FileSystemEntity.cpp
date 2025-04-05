#include "FileSystemEntity.hpp"


FileSystemEntity::FileSystemEntity(const std::string &path, const std::string &name) 
    : _path(path), _name(name)    
{}

std::string FileSystemEntity::getFullPath() const {
    std::string pathSeparator = OsSpecificConfig::getPathSeparator();

    if (utils::endsWith(_path, pathSeparator)) {
        return _path + _name;
    }

    return _path + pathSeparator + _name;
}
