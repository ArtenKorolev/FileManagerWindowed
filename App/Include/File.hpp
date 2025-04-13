#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include <fstream>
#include <filesystem>
#include "Directory.hpp"
#include "Path.hpp"


class File {
public:
    File() = default;
    File(const ExistingPath &path);
    const std::string &getPath() const;
    std::string getName() const;
private:
    ExistingPath _path;
};


class FileCreator {
public:
    void createFile(const Path &path) const;
};


class FileDeleter {
public:
    void deleteFile(const File &path) const;
};


class FileMover {
public:
    void moveFile(const File &file, const Directory &directoryToMove) const;
};


class FileCopier {
public:
    void copyFile(const File &file, const Directory &directoryToCopy);
};


class FileWriter {
public:
    void wirteToFileEnd(const File &file, const std::string &text);
};


#endif // _FILE_HPP_
