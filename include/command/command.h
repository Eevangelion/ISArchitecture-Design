#pragma once

#include <vector>
#include <string>

class command_t 
{
public:
    command_t();
    virtual ~command_t();
    
    void add_argument(std::string const& argument);
    virtual std::string process() const = 0;

protected:
    std::vector<std::string> const& get_arguments() const;

private:
    std::vector<std::string> arguments_;
};
