#include "Application.hpp"


Application::Application(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {
        _arguments.emplace_back(argv[i]);
    }
}

int Application::run() {
    return EXIT_SUCCESS;
}
