#include "command/echo.h"

echo_command_t::echo_command_t(std::vector<std::string> const& arguments)
    : command_t(arguments)
{ 
}

echo_command_t::~echo_command_t() 
{
}

std::string echo_command_t::process() const 
{
    std::string result;
    for (auto const& arg : get_arguments())
        result += arg;

    return result;
}