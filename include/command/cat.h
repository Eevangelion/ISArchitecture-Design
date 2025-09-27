#pragma once

#include "command.h"

#include <string>

class cat_command_t : public command_t
{
public:
    cat_command_t();
    ~cat_command_t();

    std::string process() override;
};