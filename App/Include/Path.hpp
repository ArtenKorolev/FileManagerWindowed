#ifndef _PATH_HPP_
#define _PATH_HPP_

#include <string>
#include "FileSystemAnalyzer.hpp"


class Path {
public:
    Path(const std::string &path);
    const std::string &getPath() const;
private:
    std::string _path;
};


#endif // _PATH_HPP_
