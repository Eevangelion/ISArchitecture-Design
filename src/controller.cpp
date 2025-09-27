#include "controller.h"

controller::controller() {
    this->lexer = new lexer_t;
    this->parser = new parser_t;
    this->pipeline_processor = new pipeline_processor_t;
}

std::string controller::process(std::string& input) {
    auto tokens = this->lexer->tokenize(input);
    auto cmds = this->parser->parse(tokens);
    return this->pipeline_processor->process_commands(cmds);
}