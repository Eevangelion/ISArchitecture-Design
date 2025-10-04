#include "command/cat.h"
#include "error_handler.h"

#include <filesystem>
#include <stdexcept>

cat_command_t::cat_command_t(std::vector<std::string> const& arguments) 
    : file_command_t(arguments)
{
}

cat_command_t::~cat_command_t() 
{
}

std::string cat_command_t::process() const
{
    std::string result;
    for (auto const& path : get_arguments()) 
    {
        if (!std::filesystem::exists(path)) {
            error_handler_t& error_handler = error_handler_t::get_instance();
            error_handler.throw_error(error_handler_t::error_type::FILE_NOT_FOUND_EXCEPTION, "File " + path + " does not exist.");
        }

        result += read_file(path);
    }

    return result;
};