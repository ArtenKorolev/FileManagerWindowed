#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE("Simple test to ensure Catch2 is working") {
    REQUIRE(1 + 1 == 2);
    REQUIRE_FALSE(1 + 1 == 3);
}
