#ifndef _PATH_HPP_
#define _PATH_HPP_

#include <string>
#include "FileSystemAnalyzer.hpp"
#include "Utils.hpp"
#include "OsSpecificConfig.hpp"


class Path {
public:
    Path() = default;
    Path(const std::string &path, const std::string &name);
    const std::string &getFullPath() const;
    const std::string &getPath() const;
    const std::string &getName() const;
protected:
    std::string _path;
    std::string _name;
    std::string _buildFullPath(const std::string &path, const std::string &name) const;
};


class ExistingPath : public Path {
public:
    ExistingPath() = default;
    ExistingPath(const std::string &path, const std::string &name);
    void diveInto(const std::string &name);
private:
    void _throwIfPathIsNotExist() const;
};


#endif // _PATH_HPP_
