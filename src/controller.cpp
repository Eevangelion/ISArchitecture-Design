#include "controller.h"

controller_t::controller_t() 
    : lexer_(new lexer_t())
    , parser_(new parser_t())
    , pipeline_processor_(new pipeline_processor_t())
{
}

controller_t::~controller_t()
{
}

std::string controller_t::process(std::string const& argument) 
{
    auto tokens = lexer_->tokenize(argument);
    auto cmds = parser_->parse(tokens);
    return pipeline_processor_->process_commands(cmds);
}