#include "command/file_command.h"

#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <filesystem>

file_command_t::file_command_t(std::vector<std::string> const& arguments) 
    : command_t(arguments)
{
}

file_command_t::~file_command_t()
{
}

std::string file_command_t::read_file(std::string const& name) const 
{
    std::ifstream in(name, std::ios::binary | std::ios::ate);
    if (!in) 
        return {};

    std::string content;
    content.reserve(in.tellg());
    in.seekg(0);
    content.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    return content;
}

bool file_command_t::is_file_exists(std::string const& name) const 
{
    return std::filesystem::exists(name);
}