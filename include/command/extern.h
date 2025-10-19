#pragma once 

#include "command.h"

/*
* Класс команды, отвечающий за вызов внешних программ.
*/
class extern_command_t : public command_t
{
public:
    /*
    * Принимает имя незнакомой команды; может принимать аргументы. 
    */
    explicit extern_command_t(std::string const& command_name, std::vector<std::string> const& arguments = {});
    ~extern_command_t();

    /*
    * Передает имя команды и аргументы в системную консоль и возвращает
    * результат исполнения. 
    */
    std::string process() const override;

private:
    std::string command_name_;
};