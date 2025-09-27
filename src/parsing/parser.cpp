#include "parsing/parser.h"

#include "../include/command/cat.h"

#include <iterator>
#include <string>
#include <iostream>

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
    // if (name == "echo") return std::make_unique<echo_command_t>(args);
    // if (name == "cat")  return std::make_unique<cat_command_t>(args);
    // if (name == "wc")   return std::make_unique<wc_command_t>(args);
    // if (name == "pwd")  return std::make_unique<pwd_command_t>(args);
    // if (name == "exit") return std::make_unique<exit_command_t>(args);

    auto test_command = [&](std::string const& parsed_command)
    {
        std::cout << "parsed command " << parsed_command << std::endl;
        std::cout << "current command " << name << std::endl;
        std::cout << "commands " << " ";
        for (auto const& arg : args)
            std::cout << arg << " ";
    
        std::cout << std::endl;
    };

    if (name == "echo") test_command("echo");
    if (name == "cat")  test_command("cat");
    if (name == "wc")   test_command("wc");
    if (name == "pwd")  test_command("pwd");
    if (name == "exit") test_command("exit");

    return std::make_unique<cat_command_t>();

    // throw std::runtime_error("no such command implemented!");
}
