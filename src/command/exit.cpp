#include <string>

#include "command/exit.h"
#include "exception/exception.h"

std::string exit_command::process() {
    throw exit_exception();
}