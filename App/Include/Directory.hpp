#ifndef _DIRECTORY_HPP_
#define _DIRECTORY_HPP_

#include <string>
#include <vector>
#include "FileSystemAnalyzer.hpp"
#include "Path.hpp"


class Directory {
public:
    Directory() = default;
    Directory(const ExistingPath &path);
    const std::string &getPath() const;
    const std::string &getName() const;
private:
    ExistingPath _path;
};


class DirectoryCreator {
public:
    void createDirectory(const Path &where) const;
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


#endif // _DIRECTORY_HPP_
