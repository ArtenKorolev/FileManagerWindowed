#include "FileSystemAnalyzer.hpp"


bool FileSystemAnalyzer::isFile(const FileSystemEntity &entity) {
    return std::filesystem::is_regular_file(
        std::filesystem::path(entity.getFullPath())
    );
}

bool FileSystemAnalyzer::isDirectory(const FileSystemEntity &entity) {
    return std::filesystem::is_directory(
        std::filesystem::path(entity.getFullPath())
    );
}

bool FileSystemAnalyzer::isEntityExists(const FileSystemEntity &entity) {
    return std::filesystem::exists(
        std::filesystem::path(entity.getFullPath())
    );
}
