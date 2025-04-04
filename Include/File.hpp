#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include "Utils.hpp"


class File {
public:
    File() = default;
    File(const std::string &path, const std::string &name);
    std::string getFullPath() const ;
private:
    std::string _path, _name;
};


#endif // _FILE_HPP_
