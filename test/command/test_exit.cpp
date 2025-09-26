#include "command/exit.h"
#include "exception/exception.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Throwing the application exit exception") {
    exit_command cmd;
    REQUIRE_THROWS_AS(cmd.process(), exit_exception);
}