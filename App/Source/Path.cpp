#include "Path.hpp"


Path::Path(const std::string &path, const std::string &name) 
    : _path(_buildFullPath(path, name))
{}

const std::string &Path::getFullPath() const {
    return _buildFullPath(_path, _name);
}

std::string Path::_buildFullPath(const std::string &path, const std::string &name) const {
    if (utils::endsWith(path, OsSpecificConfig::getPathSeparator())) {
        return path + name;
    } 
    else {
        return path + OsSpecificConfig::getPathSeparator() + name;
    }
}

const std::string &Path::getPath() const {
    return _path;
}

const std::string &Path::getName() const {
    return _name;
}


ExistingPath::ExistingPath(const std::string &path, const std::string &name)
    : Path(path, name)
{
    _throwIfPathIsNotExist();
}

void ExistingPath::diveInto(const std::string &name) {
    _path = _buildFullPath(_path, name);
    _throwIfPathIsNotExist();
}

void ExistingPath::_throwIfPathIsNotExist() const {
    if (!FileSystemAnalyzer::isEntityExists(_path)) {
        throw std::invalid_argument("Путь не существует");
    }
}
