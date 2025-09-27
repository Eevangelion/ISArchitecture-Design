#include "controller.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Controller: echo") 
{
    controller_t cont;
    std::string result = cont.process("echo kek");

    std::string expected = "kek";
    REQUIRE(result == expected);
};

TEST_CASE("Controller: wc") 
{
    controller_t cont;
    std::string result = cont.process("wc ./tests/command/test_filedata/1.txt");

    std::string expected = "0 3 21";
    REQUIRE(result == expected);
};

TEST_CASE("Controller: cat") 
{
    controller_t cont;
    std::string result = cont.process("cat ./tests/command/test_filedata/1.txt");

    std::string expected = "First test successful";
    REQUIRE(result == expected);
};