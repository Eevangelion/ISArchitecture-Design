#ifndef HW1_COMMAND_WC_H_
#define HW1_COMMAND_WC_H_

#include "command/command.h"

class wc_command_t : command_t {

public:
    wc_command_t();
    ~wc_command_t();
    
    std::string process() override;
};


#endif