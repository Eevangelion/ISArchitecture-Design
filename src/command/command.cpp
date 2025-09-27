#include "command/command.h"

#include <filesystem>
#include <fstream>

command_t::command_t() 
{
}

command_t::~command_t() 
{
}

void command_t::add_argument(std::string const& argument) 
{
    arguments_.push_back(argument);
}

std::string command_t::read_file(std::string const& file_name) 
{
    auto size = std::filesystem::file_size(file_name);
    std::string content(size, '\0');
    std::ifstream in(file_name);
    in.read(&content[0], size);
    return content;
}

std::vector<std::string> const& command_t::get_arguments() const
{
    return arguments_;
}

bool command_t::is_file_exists(std::string const& name) 
{
    return std::filesystem::exists(name);
}
