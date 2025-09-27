#pragma once

#include <vector>
#include <string>

/*
* Класс, отвечающий за токенизацию ввода.
*/

class lexer_t 
{
public:
    lexer_t();
    ~lexer_t();

    /*
    * Токенизирует ввод с поддержкой кавычек; при некорректной последовательности
    * кавычек выдает исключение std::runtime_error.
    */
    std::vector<std::string> tokenize(std::string const& input) const;
};