#include "Directory.hpp"


Directory::Directory(const std::string &path, const std::string &name) 
    : FileSystemEntity(path, name)
{}

void DirectoryCreator::createDirectory(const Directory &directory) {
    const std::string fullPath = directory.getFullPath();

    if (!std::filesystem::create_directory(fullPath)) {
        throw std::runtime_error("Failed to create directory: " + fullPath);
    }
}

void DirectoryDeleter::deleteDirectory(const Directory &directory) {
    const std::string fullPath = directory.getFullPath();

    if (std::filesystem::remove_all(fullPath) == 0) {
        throw std::runtime_error("Failed to delete directory: " + fullPath);
    }
}

std::vector<std::string> DirectoryObserver::listDirectory(const Directory &directory) {
    const std::string fullPath = directory.getFullPath();
    std::vector<std::string> fileList;

    if (!FileSystemAnalyzer::isEntityExists(std::make_shared<Directory>(directory)) || !FileSystemAnalyzer::isDirectory(std::make_shared<Directory>(directory))) {
        throw std::runtime_error("Directory does not exist: " + fullPath);
    }

    for (const auto &entry : std::filesystem::directory_iterator(fullPath)) {
        fileList.push_back(entry.path().filename().string());
    }

    return fileList;
}
