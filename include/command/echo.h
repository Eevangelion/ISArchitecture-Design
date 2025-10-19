#pragma once

#include "command.h"

/*
* Класс команды, отвечающий за команду echo.
*/
class echo_command_t : public command_t 
{
public:
    /*
    * Может принимать аргументы; см. конструктор command_t
    */
    explicit echo_command_t(std::vector<std::string> const& arguments = {});
    ~echo_command_t();
    
    /*
    * Возвращает переданные аргументы через пробел.
    */
    std::string process() const override;
};