#include "environment.h"

environment_t& environment_t::get_instance()
{
    static environment_t enviroment;
    return enviroment;
}

void environment_t::set_variable(std::string const& key, std::string const& value)
{
    variables_[key] = value;
}

std::string environment_t::get_variable(std::string const& key) const
{
    if (variables_.count(key))
        return variables_.at(key);
    
    return "";
}