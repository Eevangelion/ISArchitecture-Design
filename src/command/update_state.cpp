#include "command/update_state.h"
#include "environment.h"

#include <string>

update_state_command_t::update_state_command_t(std::string const& key, std::string const& value) 
    : key(key)
    , value(value)
    , env(environment_t::get_instance()) 
{
}

update_state_command_t::~update_state_command_t()
{
}

std::string update_state_command_t::process() const 
{   
    this -> env.set_variable(this->key, this->value);
    return "";
}