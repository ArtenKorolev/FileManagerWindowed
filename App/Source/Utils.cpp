#include "Utils.hpp"


bool utils::endsWith(const std::string &str, const std::string &suffix) { 
    if (str.length() < suffix.length()) {
        return false;
    }
    
    return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
}

std::string utils::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();

    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm* now_tm = std::localtime(&now_time_t);

    std::ostringstream oss;
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    oss << buffer;
    return oss.str();
}

