#include "Path.hpp"


Path::Path(const std::string &path)
    : _path(path)
{
    if (!FileSystemAnalyzer::isEntityExists({_path, ""})) {
        throw std::invalid_argument("Путь не существует");
    }
}

const std::string &Path::getPath() const {
    return _path;
}
