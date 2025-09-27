#include "command/echo.h"

std::string echo_command_t::process() {
    std::string result;
    for (auto& arg : get_arguments()) {
        result += arg;
    }
    return result;
}