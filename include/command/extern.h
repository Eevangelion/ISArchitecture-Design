#pragma once 

#include "command.h"

class extern_command_t : public command_t
{
public:
    extern_command_t(std::string const& command_name, std::vector<std::string> const& arguments = {});
    ~extern_command_t();

    std::string process() const override;

private:
    std::string command_name_;
};