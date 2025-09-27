#pragma once

#include <stdexcept>

/*
* Класс-исключение, нужный для обработки выхода из программы.
*/
class exit_exception : public std::exception 
{
    const char* what() const noexcept 
    {
        return "Exiting the application.";
    } 
};
