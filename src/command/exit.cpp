#include "command/exit.h"
#include "../include/error_handler.h"

exit_command_t::exit_command_t()
{
}

exit_command_t::~exit_command_t() 
{
}

std::string exit_command_t::process() const
{
    error_handler_t::get_instance().throw_error(error_handler_t::error_type::EXIT_EXCEPTION);
}