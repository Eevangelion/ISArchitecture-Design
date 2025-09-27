#pragma once

#include "command.h"

class file_command_t : public command_t 
{
public:
    file_command_t(std::vector<std::string> const& arguments = {});
    virtual ~file_command_t();

protected:
    std::string read_file(std::string const& file_name) const;
    bool is_file_exists(std::string const& file_name) const;
};