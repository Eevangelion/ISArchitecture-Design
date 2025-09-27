#include "command/extern.h"

#include <array>
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
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command_name_.c_str(), "r"), pclose);
    
    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) 
        result += buffer.data();

    return result;
}