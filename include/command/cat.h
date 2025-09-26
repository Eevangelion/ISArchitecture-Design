#ifndef HW1_COMMAND_CAT_H_
#define HW1_COMMAND_CAT_H_

#include <string>
#include "command.h"

class cat_command : public command {
    public:
        cat_command();
        std::string process() override;
        ~cat_command();
};

#endif