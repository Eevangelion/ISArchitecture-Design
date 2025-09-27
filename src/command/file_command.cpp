#include "command/file_command.h"

#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <filesystem>

file_command_t::file_command_t() 
{
}

file_command_t::~file_command_t()
{
}

std::string file_command_t::read_file(const std::string& name) const {
    // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    auto size = std::filesystem::file_size(name);
    std::string content(size, '\0');
    std::ifstream in(name);
    in.read(&content[0], size);
    return content;
}

bool file_command_t::is_file_exists(const std::string& name) const {
    // https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exists-using-standard-c-c11-14-17-c
    struct stat buffer;   
    return (stat (name.c_str(), &buffer) == 0); 
}