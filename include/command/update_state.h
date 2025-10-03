#pragma once

#include "environment.h"
#include "command.h"

class update_state_command_t : public command_t {
    public:
        update_state_command_t(std::string const& key, std::string const& value);
        ~update_state_command_t();

        std::string process() const override;

    private:
        environment_t env;
        std::string key;
        std::string value; 

};