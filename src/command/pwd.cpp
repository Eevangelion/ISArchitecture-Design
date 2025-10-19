#include "command/pwd.h"

#include <filesystem>

pwd_command_t::pwd_command_t()
{
}

pwd_command_t::~pwd_command_t() 
{
}

std::string pwd_command_t::process() const
{
    return std::filesystem::current_path().string();
}