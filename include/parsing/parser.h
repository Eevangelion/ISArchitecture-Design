#pragma once

#include "command/command.h"

#include <vector>
#include <memory>

/*
* Класс, отвечающий за синтаксический анализ токенов и построение команд по правилам.
*/
class parser_t 
{
public:
    parser_t();
    ~parser_t();

    /*
    * Определяет первую строку как название команды или вызов внешней программы,
    * после чего конструирует соответствующую команду с аргументами из остальных
    * строк.
    */
    std::vector<std::unique_ptr<command_t>> parse(std::vector<std::string> const& tokens) const;

private:
    std::unique_ptr<command_t> make_command(std::string const& name, std::vector<std::string> const& args) const;
};