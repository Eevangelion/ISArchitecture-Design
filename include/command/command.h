#pragma once

#include <vector>
#include <string>

class command_t 
{
public:
    command_t();
    virtual ~command_t();
    
    void add_argument(std::string const& argument);
    virtual std::string process() {}

protected:
    std::vector<std::string> const& get_arguments() const;

protected:
    std::string read_file(std::string const& file_name);
    bool is_file_exists(std::string const& file_name);

private:
    std::vector<std::string> arguments_;
};
