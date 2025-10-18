#pragma once

#include <vector>
#include <string>

/*
* Абстрактный класс, определяющий общие методы для всех команд. 
*/
class command_t 
{
public:

    /*
    * В конструктор принимается список аргументов, которые записываются
    * в arguments_.
    */
    explicit command_t(std::vector<std::string> const& arguments = {});
    virtual ~command_t();
    
    /*
    * Добавляет один аргумент в arguments_.
    */
    void add_argument(std::string const& argument);

    /*
    * Выполняет специфичную для команды логику.
    */
    virtual std::string process() const = 0;

protected:
    std::vector<std::string> const& get_arguments() const;

private:
    std::vector<std::string> arguments_;
};
