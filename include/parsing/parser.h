#pragma once

#include "command/command.h"

#include <vector>
#include <memory>

class parser_t 
{
public:
    parser_t();
    ~parser_t();

    std::vector<std::unique_ptr<command_t>> parse(std::vector<std::string> const& tokens) const;

private:
    std::unique_ptr<command_t> make_command(std::string const& name, std::vector<std::string> const& args) const;
};