#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include <fstream>
#include <filesystem>
#include "Directory.hpp"
#include "FileSystemEntity.hpp"
#include "FileSystemAnalyzer.hpp"


class File : public FileSystemEntity {
public:
    File() = default;
    File(const std::string &path, const std::string &name);
    const std::string &getName() const;
};


class FileCreator {
public:
    void createFile(const FileSystemEntity &file) const;
};


class FileDeleter {
public:
    void deleteFile(const File &file) const;
};


class FileMover {
public:
    void moveFile(File &file, const Directory &directoryToMove) const;
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
