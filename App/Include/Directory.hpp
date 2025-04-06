#ifndef _DIRECTORY_HPP_
#define _DIRECTORY_HPP_

#include <string>
#include <vector>
#include "FileSystemAnalyzer.hpp"
#include "File.hpp"


class Directory : public FileSystemEntity {
public:
    Directory() = default;
    Directory(const std::string &path, const std::string &name);
};


class DirectoryCreator {
public:
    void createDirectory(const FileSystemEntity &directory) const;
};


class DirectoryDeleter {
public:
    void deleteDirectory(const Directory &directory) const;
};


class DirectoryObserver {
public:
    std::vector<std::string> listDirectory(const Directory &directory) const;
};


class DirectoryMover {
public:
    void moveDirectory(Directory &directory, const Directory &whereToMove) const;
};


class DirectoryCopier {
public:
    void copyDirectory(const Directory &directory, const Directory &whereToCopy);
};


#endif // _DIRECTORY_HPP_
