#include "File.hpp"


File::File(const std::string &path, const std::string &name) 
    : _path(path), _name(name) 
{}

std::string File::getFullPath() const {
    std::string pathSeparator = OsSpecificConfig::getPathSeparator();

    if (utils::endsWith(_path, pathSeparator)) {
        return _path + _name;
    }

    return _path + pathSeparator + _name;
}

void FileCreator::createFile(const File &file) {
    std::ofstream ofs(file.getFullPath());

    if (!ofs) {
        throw std::runtime_error("Failed to create file: " + file.getFullPath());
    }

    ofs.close();
}

void FileDeleter::deleteFile(const File &file) {
    const std::string fullPath = file.getFullPath();
    
    if (std::remove(fullPath.c_str()) != 0) {
        throw std::runtime_error("Failed to delete file: " + fullPath);
    }
}
