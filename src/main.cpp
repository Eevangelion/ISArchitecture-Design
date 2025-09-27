// #include "controller.h"
#include <stdio.h>
#include <iostream>

#include "../include/parsing/lexer.h"
#include "../include/controller.h"
#include "../include/exception/exception.h"

int main(int argc, char* argv[]) 
{
    try 
    {
        std::string line;
        std::unique_ptr<controller_t> controller;
        controller.reset(new controller_t());
        while (std::getline(std::cin, line)) 
        { 
            std::cout << controller->process(line) << std::endl;
        }
    }
    catch(exit_exception const& e)
    {
        std::cout << "Exit!\n";
    }
    catch(std::runtime_error const& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}