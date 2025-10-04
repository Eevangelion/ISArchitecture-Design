#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "command/echo.h"

TEST_CASE("Echo: Hello world!") 
{
    echo_command_t echo_com;
    echo_com.add_argument("Hello world!");
    std::string result = echo_com.process();

    REQUIRE(result == "Hello world!");
}