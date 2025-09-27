#pragma once

#include "command/command.h"

class pipeline_processor_t 
{
public:
    std::string process_commands(std::vector<std::unique_ptr<command_t>> const& commands);
};