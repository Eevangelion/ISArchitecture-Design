#pragma once

#include "command/file_command.h"

#include <string>

class cat_command_t : public file_command_t
{
public:
    cat_command_t();
    ~cat_command_t();

    std::string process() const override;
};