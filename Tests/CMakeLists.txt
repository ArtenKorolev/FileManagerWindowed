include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1 
)

FetchContent_MakeAvailable(catch2)

file(GLOB TEST_SOURCES "*.cpp") 

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests Catch2::Catch2WithMain)

enable_testing()

add_test(
    NAME all_tests
    COMMAND tests
)