#include <command/pwd.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Prints current directory") {
    pwd_command cmd;
    REQUIRE(cmd.process() == std::filesystem::current_path());
}