#pragma once 

#include "command/file_command.h"

class wc_command_t : public file_command_t 
{
public:
    wc_command_t(std::vector<std::string> const& arguments = {});
    ~wc_command_t();
    
    std::string process() const override;
};