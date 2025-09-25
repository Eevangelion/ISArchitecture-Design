#include "controller.h"

controller::controller() {
    this->_lexer = new lexer;
    this->_parser = new parser;
    this->_pipeline_processor = new pipeline_processor;
}

std::string controller::process(std::string& input) {}