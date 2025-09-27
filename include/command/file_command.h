#pragma once

#include "command.h"

/*
* Абстрактный класс, определяющий общие методы команд, работающих с файлами.
*/
class file_command_t : public command_t 
{
public:

    /*
    * Может принимать аргументы; см. конструктор command_t
    */
    file_command_t(std::vector<std::string> const& arguments = {});
    virtual ~file_command_t();

protected:

    /*
    * Считывает содержимое файла; при невозможности считать файл возвращает
    * пустую строку.
    */
    std::string read_file(std::string const& file_name) const;
    bool is_file_exists(std::string const& file_name) const;
};