#include "command/command.h"

class file_command_t : public command_t {
protected:
    std::string read_file(std::string const&) const;
    bool is_file_exists(std::string const&) const;
public:
    file_command_t();
    virtual ~file_command_t();
};