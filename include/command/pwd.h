#pragma once

#include "command.h"

class pwd_command_t : public command_t
{
public:
    pwd_command_t();
    ~pwd_command_t();

    std::string process() const override;
};