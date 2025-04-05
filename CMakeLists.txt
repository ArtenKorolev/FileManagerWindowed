cmake_minimum_required(VERSION 3.10)

project(FileManagerWindowed)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ${CMAKE_SOURCE_DIR}/App/Include
)

file(GLOB CPP_SOURCES 
    "${CMAKE_SOURCE_DIR}/App/Source/*.cpp"
)

# Core app code
add_library(
    AppCode 
    "App/Source/File.cpp"
    "App/Source/Application.cpp"
    "App/Source/Directory.cpp"
    "App/Source/FileSystemAnalyzer.cpp"
    "App/Source/FileSystemEntity.cpp"
    "App/Source/OsSpecificConfig.cpp"
    "App/Source/Utils.cpp"
)

# Executable with entrypoint
add_executable(
    FileManagerWindowed 
    "App/Source/Main.cpp"
)

# Adding the core app code to the executable
target_link_libraries(FileManagerWindowed AppCode)

include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)

FetchContent_MakeAvailable(catch2)

file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/Tests/*.cpp") 

add_executable(tests ${TEST_SOURCES})

# Adding the core app code for testing
target_link_libraries(tests AppCode Catch2::Catch2WithMain)

enable_testing()

add_test(
    NAME all_tests
    COMMAND tests
)
