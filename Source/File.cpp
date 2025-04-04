#include "File.hpp"


File::File(const std::string &path, const std::string &name) 
    : _path(path), _name(name) 
{}

std::string File::getFullPath() const {
    if (utils::endsWith(_path, "/")) {
        return _path + _name;
    }

    return _path + "/" + _name;
}
