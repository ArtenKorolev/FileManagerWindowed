#include "File.hpp"


File::File(const std::string &path, const std::string &name) 
    : FileSystemEntity(path, name)
{
    if (!FileSystemAnalyzer::isEntityExists({path, name}) || !FileSystemAnalyzer::isFile({path, name})) {
        throw std::runtime_error("File does not exist: " + getFullPath());
    }
}

const std::string &File::getName() const {
    return _name;
}

void FileCreator::createFile(const FileSystemEntity &file) const {
    std::ofstream ofs(file.getFullPath());

    if (!ofs) {
        throw std::runtime_error("Failed to create file: " + file.getFullPath());
    }

    ofs.close();
}

void FileDeleter::deleteFile(const File &file) const {
    const std::string fullPath = file.getFullPath();
    
    if (std::remove(fullPath.c_str()) != 0) {
        throw std::runtime_error("Failed to delete file: " + fullPath);
    }
}

void FileMover::moveFile(File &file, const Directory &directoryToMove) const {
    const std::string oldFilePath = file.getFullPath(); 
    file.move(directoryToMove.getFullPath());

    try {
        std::filesystem::rename(oldFilePath, file.getFullPath());
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to move file from " + oldFilePath + " to " + file.getFullPath() + ": " + e.what());
    }
}

void FileCopier::copyFile(const File &file, const Directory &directoryToCopy) {
    const std::string sourcePath = file.getFullPath();
    const std::string destinationPath = directoryToCopy.getFullPath() + OsSpecificConfig::getPathSeparator() + file.getName();

    try {
        std::filesystem::copy(sourcePath, destinationPath, std::filesystem::copy_options::overwrite_existing); // Копируем файл
    } catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to copy file from " + sourcePath + " to " + destinationPath + ": " + e.what());
    }
}
