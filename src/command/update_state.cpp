#include "command/update_state.h"

#include <string>

update_state_command_t::update_state_command_t(std::string const& key, std::string const& value) 
    : key(key),
    value(value) 
{
}

update_state_command_t::~update_state_command_t()
{
}

std::string update_state_command_t::process() const {
    //env.set_storage(this->key, this->value)
    return this->value;
}