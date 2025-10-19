#include "command/exit.h"
#include "error_handler.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Throwing the application exit exception") {
    exit_command_t cmd;
    REQUIRE_THROWS_AS(cmd.process(), error_handler_t::error_type);
}