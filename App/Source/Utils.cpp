#include "Utils.hpp"


bool utils::endsWith(const std::string &str, const std::string &suffix) { 
    if (str.length() < suffix.length()) {
        return false;
    }
    
    return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
}
