#include "FileSystemAnalyzer.hpp"


bool FileSystemAnalyzer::isFile(const std::string &path) {
    return std::filesystem::is_regular_file(
        std::filesystem::path(path)
    );
}

bool FileSystemAnalyzer::isDirectory(const std::string &path) {
    return std::filesystem::is_directory(
        std::filesystem::path(path)
    );
}

bool FileSystemAnalyzer::isEntityExists(const std::string &path) {
    return std::filesystem::exists(
        std::filesystem::path(path)
    );
}
