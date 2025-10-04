#pragma once

#include "command.h"
#include "environment.h"

class update_state_command_t : public command_t 
{
public:
    update_state_command_t(std::string const& key, std::string const& value);
    ~update_state_command_t();

    std::string process() const override;
private:
    std::string key;
    std::string value;
    environment_t& env;
};