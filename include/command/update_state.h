#pragma once

#include "command.h"
#include "environment.h"

/*
* Класс команды, отвечающий за сохранение переменных в окружении.
*/
class update_state_command_t : public command_t 
{
public:
    /*
    * В качестве параметров принимает ключ и значение переменной, а также получает значение
    * синглтона окружения.
    */
    update_state_command_t(std::string const& key, std::string const& value);
    ~update_state_command_t();

    /*
    * При помощи специального метода синглтона окружения сохраняет значение по ключу.
    */
    std::string process() const override;
private:
    std::string key;
    std::string value;
    environment_t& env;
};