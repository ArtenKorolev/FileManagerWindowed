#ifndef _DIRECTORY_HPP_
#define _DIRECTORY_HPP_

#include <string>
#include <vector>
#include "FileSystemAnalyzer.hpp"


class Directory : public FileSystemEntity {
public:
    Directory() = default;
    Directory(const std::string &path, const std::string &name);
};


class DirectoryCreator {
public:
    void createDirectory(const Directory &directory);
};


class DirectoryDeleter {
public:
    void deleteDirectory(const Directory &directory);
};


class DirectoryObserver {
public:
    std::vector<std::string> listDirectory(const Directory &directory);
};


#endif // _DIRECTORY_HPP_
