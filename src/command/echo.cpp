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

    auto const& arguments = get_arguments();
    for (size_t i = 0; i < arguments.size(); ++i)
        result += (arguments[i] + (i == arguments.size() - 1 ? "" : " "));

    return result;
}