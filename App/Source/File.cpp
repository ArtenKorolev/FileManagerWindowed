#include "File.hpp"


File::File(const ExistingPath &path) 
    : _path(path)
{
    if (!FileSystemAnalyzer::isFile(path.getPath())) {
        throw std::invalid_argument("Объект не является файлом: " + path.getPath());
    }
}

const std::string &File::getPath() const {
    return _path.getFullPath();
}

std::string File::getName() const {
    return _path.getName();
}

void FileCreator::createFile(const Path &path) const {
    std::ofstream ofs(path.getFullPath());

    if (!ofs) {
        throw std::runtime_error("Failed to create file: " + path.getFullPath());
    }

    ofs.close();
}

void FileDeleter::deleteFile(const File &file) const {
    const std::string fullPath = file.getPath();
    
    if (std::remove(fullPath.c_str()) != 0) {
        throw std::runtime_error("Failed to delete file: " + fullPath);
    }
}

void FileMover::moveFile(const File &file, const Directory &directoryToMove) const {
    try {
        std::filesystem::rename(file.getPath(), directoryToMove.getPath() + OsSpecificConfig::getPathSeparator() + file.getName());
    }
    catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to move file:" + std::string(e.what()));
    }
}

void FileCopier::copyFile(const File &file, const Directory &directoryToCopy) {
    const std::string sourcePath = file.getPath();
    Path destinationPath(directoryToCopy.getPath(), file.getName());

    try {
        std::filesystem::copy(sourcePath, destinationPath.getPath(), std::filesystem::copy_options::overwrite_existing);
    } catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to copy file from " + sourcePath + " to " + destinationPath.getPath() + ": " + e.what());
    }
}

void FileWriter::wirteToFileEnd(const File &file, const std::string &text) {
    std::ofstream outFile(file.getPath(), std::ios::app);

    if (!outFile) {
        throw std::runtime_error("Failed to open file.");
    }

    outFile << text;
    outFile.close();
}
