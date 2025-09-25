#ifndef HW1_CONTROLLER_H_
#define HW1_CONTROLLER_H_

#include "parsing/lexer.h"
#include "parsing/parser.h"
#include "pipeline_processor.h"
#include <string>

class controller {
private:
    lexer* _lexer;
    parser* _parser;
    pipeline_processor* _pipeline_processor;
public:
    controller();
    std::string process(std::string&);
    ~controller() {}
};

#endif