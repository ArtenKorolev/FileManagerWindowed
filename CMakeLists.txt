cmake_minimum_required(VERSION 3.10)

project(FileManagerWindowed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/Include
)

file(GLOB CPP_SOURCES 
    "${CMAKE_SOURCE_DIR}/Source/*.cpp"
)

add_executable(FileManagerWindowed ${CPP_SOURCES})
