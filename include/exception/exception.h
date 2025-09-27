#pragma once

#include <stdexcept>

class exit_exception : public std::exception 
{
    const char* what() const noexcept 
    {
        return "Exiting the application.";
    } 
};
