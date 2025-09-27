#ifndef HW1_COMMAND_ECHO_H_
#define HW1_COMMAND_ECHO_H_

#include "command/command.h"

class echo_command_t : public command_t {

public:
    echo_command_t();
    ~echo_command_t();
    
    std::string process() const override;
};


#endif