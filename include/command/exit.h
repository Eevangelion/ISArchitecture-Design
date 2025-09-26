#ifndef HW1_COMMAND_EXIT_H_
#define HW1_COMMAND_EXIT_H_

#include <string>
#include "command.h"

class exit_command : public command {
    public:
        exit_command();
        std::string process() override;
        ~exit_command();
};

#endif