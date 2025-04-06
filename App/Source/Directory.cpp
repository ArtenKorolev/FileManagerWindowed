#include "Directory.hpp"


Directory::Directory(const std::string &path, const std::string &name) 
    : FileSystemEntity(path, name)
{
    if (!FileSystemAnalyzer::isEntityExists({path, name}) || !FileSystemAnalyzer::isDirectory({path, name})) {
        throw std::runtime_error("Directory does not exist: " + getFullPath());
    }
}

void DirectoryCreator::createDirectory(const FileSystemEntity &directory) const {
    const std::string fullPath = directory.getFullPath();

    if (!std::filesystem::create_directory(fullPath)) {
        throw std::runtime_error("Failed to create directory: " + fullPath);
    }
}

void DirectoryDeleter::deleteDirectory(const Directory &directory) const {
    const std::string fullPath = directory.getFullPath();

    if (std::filesystem::remove_all(fullPath) == 0) {
        throw std::runtime_error("Failed to delete directory: " + fullPath);
    }
}

std::vector<std::string> DirectoryObserver::listDirectory(const Directory &directory) const {
    std::vector<std::string> fileList;

    for (const auto &entry : std::filesystem::directory_iterator(directory.getFullPath())) {
        fileList.push_back(entry.path().filename().string());
    }

    return fileList;
}
