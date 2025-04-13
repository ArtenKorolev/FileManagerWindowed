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
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)

FetchContent_MakeAvailable(catch2)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1 
)

FetchContent_MakeAvailable(SFML)

add_library(
    AppCode 
    "App/Source/File.cpp"
    "App/Source/Application.cpp"
    "App/Source/Directory.cpp"
    "App/Source/FileSystemAnalyzer.cpp"
    "App/Source/Path.cpp"
    "App/Source/OsSpecificConfig.cpp"
    "App/Source/Utils.cpp"
)

add_executable(
    FileManagerWindowed 
    "App/Source/Main.cpp"
    "App/Source/SFMLInterface.cpp"
    "App/Source/SFMLPrimitivsDrawer.cpp"
    "App/Source/ResourceManager.cpp"
)

target_link_libraries(FileManagerWindowed PRIVATE AppCode sfml-graphics sfml-window sfml-system)

file(GLOB TEST_SOURCES "Tests/*.cpp")
add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests PRIVATE AppCode Catch2::Catch2WithMain)

enable_testing()
add_test(NAME Tests COMMAND Tests)
