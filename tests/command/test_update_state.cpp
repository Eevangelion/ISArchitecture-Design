#include "command/update_state.h"
#include "environment.h"

#include <string>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Saving a variable") {
    std::string test_key = "test";
    std::string test_value = "TEST";
    update_state_command_t cmd(test_key, test_value);
    cmd.process();
    REQUIRE(environment_t::get_instance().get_variable(test_key) == test_value);
}