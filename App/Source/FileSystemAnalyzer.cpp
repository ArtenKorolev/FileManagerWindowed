#include "FileSystemAnalyzer.hpp"


bool FileSystemAnalyzer::isFile(const std::shared_ptr<FileSystemEntity> entity) {
    return std::filesystem::is_regular_file(
        std::filesystem::path(entity->getFullPath())
    );
}

bool FileSystemAnalyzer::isDirectory(const std::shared_ptr<FileSystemEntity> entity) {
    return std::filesystem::is_directory(
        std::filesystem::path(entity->getFullPath())
    );
}

bool FileSystemAnalyzer::isEntityExists(const std::shared_ptr<FileSystemEntity> entity) {
    return std::filesystem::exists(
        std::filesystem::path(entity->getFullPath())
    );
}
