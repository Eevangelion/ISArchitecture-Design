#include "parsing/parser.h"

#include "command/echo.h"
#include "command/cat.h"
#include "command/wc.h"
#include "command/pwd.h"
#include "command/exit.h"
#include "command/extern.h"

#include <iterator>
#include <string>

parser_t::parser_t()
{
}

parser_t::~parser_t()
{
}

std::vector<std::unique_ptr<command_t>> parser_t::parse(std::vector<std::string> const& tokens) const
{
    if (tokens.empty())
        return {};

    std::vector<std::unique_ptr<command_t>> commands;
    auto it = tokens.begin();
    while (it != tokens.end()) 
    {
        auto pipe_pos = std::find(it, tokens.end(), std::string("|"));

        std::vector<std::string> segment(it, pipe_pos);
        if (!segment.empty()) 
        {
            std::string name = segment[0];
            std::vector<std::string> args(std::next(segment.begin()), segment.end());
            commands.emplace_back(make_command(name, args));
        }

        if (pipe_pos == tokens.end())
            break;
        else
            it = std::next(pipe_pos);
    }

    return commands;
}

std::unique_ptr<command_t> parser_t::make_command(std::string const& name, std::vector<std::string> const& args) const
{
    if (name == "echo") return std::make_unique<echo_command_t>(args);
    if (name == "cat")  return std::make_unique<cat_command_t>(args);
    if (name == "wc")   return std::make_unique<wc_command_t>(args);
    if (name == "pwd")  return std::make_unique<pwd_command_t>();
    if (name == "exit") return std::make_unique<exit_command_t>();

    return std::make_unique<extern_command_t>(name, args);
}
