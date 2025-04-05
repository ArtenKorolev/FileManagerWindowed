#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../App/Include/FileSystemAnalyzer.hpp"
#include "../App/Include/Directory.hpp"
#include "../App/Include/File.hpp"


TEST_CASE("Get full path worked test case") {
    const auto excpected = "path" + OsSpecificConfig::getPathSeparator() + "name";
    
    FileSystemEntity entity("path", "name");
    auto real = entity.getFullPath();
    REQUIRE(excpected == real);
    
    FileSystemEntity entity2("path/", "name");
    real = entity2.getFullPath();
    REQUIRE(excpected == real);
}

TEST_CASE("Entity exists method test case") {
    const auto homePath = OsSpecificConfig::getHomeDirectory();
    const auto real = FileSystemAnalyzer::isEntityExists(std::make_shared<Directory>(homePath, ""));

    REQUIRE(real == true);
}

TEST_CASE("Ends with function test case") {
    REQUIRE(utils::endsWith("asdfg", "fg") == true);
    REQUIRE_FALSE(utils::endsWith("", "fg") == true);
    REQUIRE_FALSE(utils::endsWith("asdfg", "s") == true);
}

TEST_CASE("File moving test case") {
    File file("path", "testfile.txt");
    file.move("newpath");
    REQUIRE(file.getFullPath() == "newpath" + OsSpecificConfig::getPathSeparator() + "testfile.txt");
}
