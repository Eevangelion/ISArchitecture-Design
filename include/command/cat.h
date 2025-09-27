#pragma once

#include "command/file_command.h"

#include <string>

class cat_command_t : public file_command_t
{
public:
    cat_command_t(std::vector<std::string> const& arguments = {});
    ~cat_command_t();

    std::string process() const override;
};