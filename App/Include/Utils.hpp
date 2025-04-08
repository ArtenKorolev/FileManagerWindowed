#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <chrono>
#include <sstream>


namespace utils {

bool endsWith(const std::string &str, const std::string &suffix);

std::string getCurrentDateTime();

}


#endif // _UTILS_HPP_
