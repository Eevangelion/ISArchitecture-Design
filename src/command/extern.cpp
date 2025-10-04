#include "command/extern.h"
#include "error_handler.h"

#include <array>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <filesystem>

extern_command_t::extern_command_t(std::string const& command_name, std::vector<std::string> const& arguments)
    : command_t(arguments)
    , command_name_(command_name)
{
}

extern_command_t::~extern_command_t()
{
}

std::string extern_command_t::process() const
{
    std::ostringstream cmd;
    cmd << command_name_;

    auto const& arguments = get_arguments();
    for (auto const& arg : arguments)
        cmd << " " << std::quoted(arg);

    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.str().c_str(), "r"), pclose);

    if (!pipe) {
        error_handler_t::get_instance().throw_error(error_handler_t::error_type::POPEN_FAILED_EXCEPTION, "popen() failed");
    }

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) 
        result += buffer.data();

    return result;
}