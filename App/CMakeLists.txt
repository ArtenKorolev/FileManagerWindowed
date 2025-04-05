include_directories(
    ${CMAKE_SOURCE_DIR}/App/Include
)

file(GLOB CPP_SOURCES 
    "${CMAKE_SOURCE_DIR}/App/Source/*.cpp"
)

add_executable(FileManagerWindowed ${CPP_SOURCES})
