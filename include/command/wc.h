#ifndef HW1_COMMAND_WC_H_
#define HW1_COMMAND_WC_H_

#include "command/file_command.h"

class wc_command_t : public file_command_t {
public:
    wc_command_t();
    ~wc_command_t();
    
    std::string process() const override;
};


#endif