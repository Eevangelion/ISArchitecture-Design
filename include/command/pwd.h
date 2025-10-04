#pragma once

#include "command.h"

/*
* Класс команды, отвечающий за команду pwd.
*/
class pwd_command_t : public command_t
{
public:
    pwd_command_t();
    ~pwd_command_t();

    /*
    * Возвращает путь до исполняемого файла.
    */
    std::string process() const override;
};