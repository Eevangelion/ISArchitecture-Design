#include "command/cat.h"

#include <stdexcept>

cat_command_t::cat_command_t() 
{
}

cat_command_t::~cat_command_t() 
{
}

std::string cat_command_t::process() 
{
    std::string result;
    for (auto const& path : get_arguments()) 
    {
        if (!is_file_exists(path))
            throw std::runtime_error("File " + path + " does not exist.");

        result += read_file(path);
    }

    return result;
};