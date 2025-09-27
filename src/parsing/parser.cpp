#include "parsing/parser.h"

#include "command/echo.h"
#include "command/cat.h"
#include "command/wc.h"
#include "command/pwd.h"
#include "command/exit.h"

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

    //пайпы - здесь надо будет делить по "|"
    std::string const& name = tokens[0];
    std::vector<std::string> args(std::next(tokens.begin()), tokens.end());

    std::vector<std::unique_ptr<command_t>> commands;
    commands.emplace_back(make_command(name, args));

    return commands;
}

std::unique_ptr<command_t> parser_t::make_command(std::string const& name, std::vector<std::string> const& args) const
{
    if (name == "echo") return std::make_unique<echo_command_t>(args);
    if (name == "cat")  return std::make_unique<cat_command_t>(args);
    if (name == "wc")   return std::make_unique<wc_command_t>(args);
    if (name == "pwd")  return std::make_unique<pwd_command_t>();
    if (name == "exit") return std::make_unique<exit_command_t>();

    return std::make_unique<cat_command_t>(); //todo
}
