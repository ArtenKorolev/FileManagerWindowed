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

void DirectoryMover::moveDirectory(Directory &directory, const Directory &whereToMove) const {
    const std::string oldDirPath = directory.getFullPath(); 
    directory.move(whereToMove.getFullPath());

    try {
        std::filesystem::rename(oldDirPath, directory.getFullPath());
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to move directory from " + oldDirPath + " to " + directory.getFullPath() + ": " + e.what());
    }
}

void DirectoryCopier::copyDirectory(const Directory &directory, const Directory &whereToCopy) {
    auto directoryElements = DirectoryObserver().listDirectory(directory);

    for (const auto &entityName : directoryElements) {
        FileSystemEntity entity(directory.getFullPath(), entityName);

        if (FileSystemAnalyzer::isDirectory(entity)) {
            copyDirectory(
                Directory(directory.getFullPath(), entityName), 
                Directory(whereToCopy.getFullPath(), entityName)
            );
        }
        else if (FileSystemAnalyzer::isFile(entity)) {
            File file(directory.getFullPath(), entityName);
            FileCopier().copyFile(file, whereToCopy);
        }
        else {
            throw std::runtime_error("Unknown entity type found during directory copy: " + entity.getFullPath());
        }
    }
}
