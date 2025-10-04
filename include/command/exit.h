#pragma once

#include "command.h"

/*
* Класс команды, отвечающий за команду exit.
*/
class exit_command_t : public command_t
{
public:
    exit_command_t();
    ~exit_command_t();
    
    /*
    * Выдаёт исключение exit_exception, определяющее выход из программы.
    */
    std::string process() const override;
};