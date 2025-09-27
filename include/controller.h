#pragma once

#include "parsing/lexer.h"
#include "parsing/parser.h"
#include "pipeline_processor.h"

class controller_t
{
public:
    controller_t();
    ~controller_t();

    std::string process(std::string const& argument);

private:
    std::unique_ptr<lexer_t> lexer_;
    std::unique_ptr<parser_t> parser_;
    std::unique_ptr<pipeline_processor_t> pipeline_processor_;
};