#ifndef HW1_PIPELINE_PROCESSOR_H_
#define HW1_PIPELINE_PROCESSOR_H_

#include <string> 
#include <vector>
#include <memory>

#include "command/command.h"

class pipeline_processor_t {

public:
    std::string process_commands(std::vector<std::unique_ptr<command_t> > commands) {}
};
#endif