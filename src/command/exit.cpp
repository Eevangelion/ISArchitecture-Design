#include "command/exit.h"
#include "../include/exception/exception.h"

exit_command_t::exit_command_t()
{
}

exit_command_t::~exit_command_t() 
{
}

std::string exit_command_t::process() const
{
    throw exit_exception();
}