#ifndef HW1_CONTROLLER_H_
#define HW1_CONTROLLER_H_

#include "parsing/lexer.h"
#include "parsing/parser.h"
#include "pipeline_processor.h"
#include <string>

class controller {
private:
    lexer_t* lexer;
    parser_t* parser;
    pipeline_processor_t* pipeline_processor;
public:
    controller();
    std::string process(std::string&);
    ~controller() {}
};

#endif