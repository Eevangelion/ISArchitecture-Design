#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "command/wc.h"

namespace {
    std::vector<std::string> filepaths = {"tests/command/test_filedata/1.txt", "tests/command/test_filedata/2", "tests/command/test_filedata/empty.txt"};
}

TEST_CASE("Wc: common file") 
{
    wc_command_t wc_com;
    wc_com.add_argument(filepaths[0]);

    std::string result = wc_com.process();
    std::string expected = "0 3 21";
    REQUIRE(result == expected);
}

TEST_CASE("Wc: empty file") 
{
    wc_command_t wc_com;
    wc_com.add_argument(filepaths[2]);

    std::string result = wc_com.process();
    std::string expected = "0 0 0";
    REQUIRE(result == expected);
}
