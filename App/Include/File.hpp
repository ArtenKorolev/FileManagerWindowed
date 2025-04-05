#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include <fstream>
#include "Directory.hpp"
#include "FileSystemEntity.hpp"
#include "FileSystemAnalyzer.hpp"


class File : public FileSystemEntity {
public:
    File() = default;
    File(const std::string &path, const std::string &name);
};


class FileCreator {
public:
    void createFile(const File &file) const;
};


class FileDeleter {
public:
    void deleteFile(const File &file) const;
};


class FileMover {
public:
    void moveFile(File &file, const std::string &pathForMoving) const;
};


#endif // _FILE_HPP_
