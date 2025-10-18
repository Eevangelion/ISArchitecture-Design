#pragma once

#include "file_command.h"

/*
* Класс команды, отвечающий за команду cat.
*/
class cat_command_t : public file_command_t
{
public:
    /*
    * Может принимать аргументы; см. конструктор command_t
    */
    explicit cat_command_t(std::vector<std::string> const& arguments = {});
    ~cat_command_t();

    /*
    * Конкатенирует содержимое файлов, пути к которым переданные в качестве
    * аргументов, и возвращает его. При невозможности выдает исключение std::runtime_error. 
    */
    std::string process() const override;
};