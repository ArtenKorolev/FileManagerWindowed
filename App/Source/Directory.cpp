#include "Directory.hpp"


Directory::Directory(const ExistingPath &path)
    : _path(path)
{
    if (!FileSystemAnalyzer::isDirectory(path.getFullPath())) {
        throw std::invalid_argument("Объект не является директорией: " + path.getFullPath());
    }
}

const std::string &Directory::getPath() const {
    return _path.getFullPath();
}

const std::string &Directory::getName() const {
    return _path.getName();
}


void DirectoryCreator::createDirectory(const Path &where) const {
    if (!std::filesystem::create_directory(where.getFullPath())) {
        throw std::runtime_error("Failed to create directory: " + where.getFullPath());
    }
}

void DirectoryDeleter::deleteDirectory(const Directory &directory) const {
    const std::string fullPath = directory.getPath();

    if (std::filesystem::remove_all(fullPath) == 0) {
        throw std::runtime_error("Failed to delete directory: " + fullPath);
    }
}

std::vector<std::string> DirectoryObserver::listDirectory(const Directory &directory) const {
    std::vector<std::string> fileList;

    for (const auto &entry : std::filesystem::directory_iterator(directory.getPath())) {
        fileList.push_back(entry.path().filename().string());
    }

    return fileList;
}

void DirectoryMover::moveDirectory(Directory &directory, const Directory &whereToMove) const {
    Path destinationPath(whereToMove.getPath(), directory.getName());
    
    try {
        std::filesystem::rename(directory.getPath(), destinationPath.getPath());
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to move directory " + std::string(e.what()));
    }
}
