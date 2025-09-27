#include "command/command.h"

command_t::command_t(std::vector<std::string> const& arguments)
    : arguments_(arguments)
{
}

command_t::~command_t()
{
}

void command_t::add_argument(std::string const& argument) 
{
    arguments_.emplace_back(argument);
}

std::vector<std::string> const& command_t::get_arguments() const
{
    return arguments_;
}