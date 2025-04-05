#ifndef _DIRECTORY_HPP_
#define _DIRECTORY_HPP_

#include <string>
#include "FileSystemEntity.hpp"


class Directory : public FileSystemEntity {
public:
    Directory() = default;
    Directory(const std::string &path, const std::string &name);
};


class DirectoryCreator {

};


class DirectoryDeleter {

};


class DirectoryObserver {

};


#endif // _ DIRECTORY_HPP_
