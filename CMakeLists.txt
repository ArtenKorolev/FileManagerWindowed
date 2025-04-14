cmake_minimum_required(VERSION 3.10)

project(FileManagerWindowed)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    "App/Include"
)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1 
)

FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)

FetchContent_MakeAvailable(catch2)

file(GLOB CPP_SOURCES "App/Source/*.cpp")

add_executable(FileManagerWindowed ${CPP_SOURCES})

target_link_libraries(FileManagerWindowed PRIVATE sfml-graphics sfml-window sfml-system)

file(GLOB TEST_SOURCES
    "App/Source/Directory.cpp"
    "App/Source/File.cpp"
    "App/Source/FileSystemAnalyzer.cpp"
    "App/Source/Logger.cpp"
    "App/Source/Path.cpp"
    "App/Source/OsSpecificConfig.cpp"
    "App/Source/Utils.cpp"
    "Tests/TestMain.cpp"
)

add_executable(Tests ${TEST_SOURCES})

target_link_libraries(Tests Catch2::Catch2WithMain)
