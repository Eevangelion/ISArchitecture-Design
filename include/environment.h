#pragma once

#include <string>
#include <map>

class environment_t
{
public: 
    static environment_t& get_instance();

    void set_variable(std::string const& key, std::string const& value);
    std::string get_variable(std::string const& key) const;

private:
    environment_t() = default;
    environment_t(environment_t const&) = delete;
    void operator=(environment_t const&) = delete;

private:
    std::map<std::string, std::string> variables_;
};
