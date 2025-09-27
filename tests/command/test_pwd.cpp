#include <command/pwd.h>

#include <filesystem>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Prints current directory") {
    pwd_command_t cmd;
    REQUIRE(cmd.process() == std::filesystem::current_path());
}