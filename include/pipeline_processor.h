#pragma once

#include "command/command.h"
#include <memory>

/*
* Класс, отвечающий за последовательную обработку команд и работу с пайпами. 
*/
class pipeline_processor_t 
{
public:

    /*
    * Принимает список команд, которые вызывает, последовательно подавая на вход следующей
    * команде результат работы предыдущей, если это необходимо. 
    */
    std::string process_commands(std::vector<std::unique_ptr<command_t>> const& commands);
};