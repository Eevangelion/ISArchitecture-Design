#pragma once

#include "command.h"

#include <string>

class exit_command_t : public command_t
{
public:
    exit_command_t();
    ~exit_command_t();
    
    std::string process() const override;
};