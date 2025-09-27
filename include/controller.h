#pragma once

#include "parsing/lexer.h"
#include "parsing/parser.h"
#include "pipeline_processor.h"

/*
* Класс-контроллер, отвечающий за управление обработкой полученной на вход строки
* и координирование действий лексера, парсера и обработчика.
*/
class controller_t
{
public:
    controller_t();
    ~controller_t();

    /*
    * Токенизирует входящую строку, из токенов строит команды по синтаксическим правилам,
    * после чего передает команды в обработчик и получает результат исполнения.
    */
    std::string process(std::string const& argument);

private:
    std::unique_ptr<lexer_t> lexer_;
    std::unique_ptr<parser_t> parser_;
    std::unique_ptr<pipeline_processor_t> pipeline_processor_;
};