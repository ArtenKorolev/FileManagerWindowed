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
    const auto real = FileSystemAnalyzer::isEntityExists({homePath, ""});

    REQUIRE(real);
}

TEST_CASE("Ends with function test case") {
    REQUIRE(utils::endsWith("asdfg", "fg") );
    REQUIRE_FALSE(utils::endsWith("", "fg"));
    REQUIRE_FALSE(utils::endsWith("asdfg", "s"));
}

TEST_CASE("Filesystem entity moving test case") {
    FileSystemEntity e("path", "testfile.txt");
    e.move("newpath");
    REQUIRE(e.getFullPath() == "newpath" + OsSpecificConfig::getPathSeparator() + "testfile.txt");
}
