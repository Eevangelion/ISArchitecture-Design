// #include "controller.h"
#include <stdio.h>
#include <iostream>

#include "../include/parsing/lexer.h"
#include "../include/controller.h"
#include "../include/error_handler.h"

int main(int argc, char* argv[]) 
{
    std::string line;
    std::unique_ptr<controller_t> controller;
    controller.reset(new controller_t());
    while (std::getline(std::cin, line)) 
        {   
            try {
                std::cout << controller->process(line) << std::endl;
            } 
            catch(error_handler_t::error_type const& e)
            {
                error_handler_t& error_handler = error_handler_t::get_instance();
                bool should_close = error_handler.handle_error(e);
                if (should_close) {
                    return 0;
                }
            }
        }

    return 0;
}