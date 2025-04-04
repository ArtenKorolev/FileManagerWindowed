#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include <vector>
#include <string>


class Application {
public:
    Application() = default; 
    Application(int argc, char **argv);
    int run();
private:
    std::vector<std::string> _arguments;
};


#endif // _APPLICATION_HPP_
