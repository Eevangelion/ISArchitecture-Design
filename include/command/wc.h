#pragma once 

#include "file_command.h"

/*
* Класс команды, отвечающий за команду wc.
*/
class wc_command_t : public file_command_t 
{
public:
    /*
    * Может принимать аргументы; см. конструктор command_t
    */
    wc_command_t(std::vector<std::string> const& arguments = {});
    ~wc_command_t();
    
    /*
    * Считывает содержимое файла в аргументах и возвращает количество слов, строк
    * и байтов в нём. Если файла не существует, выдаёт исключение std::runtime_error.
    */
    std::string process() const override;
};