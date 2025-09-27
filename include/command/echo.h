#pragma once

#include "command.h"

class echo_command_t : public command_t 
{
public:
    echo_command_t(std::vector<std::string> const& arguments = {});
    ~echo_command_t();
    
    std::string process() const override;
};