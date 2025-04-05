#ifndef _FILESYSTEMANALYZER_HPP_
#define _FILESYSTEMANALYZER_HPP_

#include <memory>
#include <filesystem>
#include "FileSystemEntity.hpp"


class FileSystemAnalyzer {
public:
    static bool isFile(const std::shared_ptr<FileSystemEntity> entity);
    static bool isDirectory(const std::shared_ptr<FileSystemEntity> entity);
    static bool isEntityExists(const std::shared_ptr<FileSystemEntity> entity);
};


#endif // _FILESYSTEMANALYZER_HPP_
