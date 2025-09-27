#include "command/cat.h"

#include <filesystem>
#include <fstream>


cat_command_t::cat_command_t() 
{
}

cat_command_t::~cat_command_t() 
{
}

std::string cat_command_t::process() const
{
    std::string result;

    auto read_file = [](std::string const& path) -> std::string
    {
        std::ifstream in(path, std::ios::binary | std::ios::ate);
        if (!in) 
            return {};

        std::string content;
        content.reserve(in.tellg());
        in.seekg(0);
        content.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
        return content;
    };

    for (auto const& path : get_arguments()) 
    {
        if (!std::filesystem::exists(path))
            throw std::runtime_error("File " + path + " does not exist.");

        result += read_file(path);
    }

    return result;
};