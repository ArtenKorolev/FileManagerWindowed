#ifndef _FILESYSTEMANALYZER_HPP_
#define _FILESYSTEMANALYZER_HPP_

#include <memory>
#include <filesystem>


class FileSystemAnalyzer {
public:
    static bool isFile(const std::string &path);
    static bool isDirectory(const std::string &path);
    static bool isEntityExists(const std::string &path);
};


#endif // _FILESYSTEMANALYZER_HPP_
