#ifndef HW1_COMMAND_PWD_H_
#define HW1_COMMAND_PWD_H_

#include <string>
#include "command.h"

class pwd_command : public command {
    public:
        pwd_command();
        std::string process() override;
        ~pwd_command();
};


#endif