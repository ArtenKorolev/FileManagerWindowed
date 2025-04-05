#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include <fstream>
#include "FileSystemEntity.hpp"


class File : public FileSystemEntity {
public:
    File() = default;
    File(const std::string &path, const std::string &name);
};


class FileCreator {
public:
    void createFile(const File &file);
};


class FileDeleter {
public:
    void deleteFile(const File &file);
};


#endif // _FILE_HPP_
