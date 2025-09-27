// #include "controller.h"
#include <stdio.h>
#include <iostream>

#include "../include/parsing/lexer.h"
#include "../include/parsing/parser.h"

int main() 
{
    try 
    {
        lexer_t lx;
        auto t1 = lx.tokenize("echo \"hello world\"");
        auto t2 = lx.tokenize("wc \"hello world\"");

        auto t3 = lx.tokenize("echo '''a b 'ab'' \"c d\"'");

        parser_t parser;
        parser.parse(t1);
    }
    catch(std::runtime_error const& e)
    {
        std::cout << e.what() << std::endl;
    }
    // for (auto const& val : t1)
    //     std::cout << val << std::endl;

    return 0;
}