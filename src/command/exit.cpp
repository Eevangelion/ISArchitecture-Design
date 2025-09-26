#include <string>

#include "command/exit.h"
#include "exception/exception.h"

exit_command::exit_command() {};

std::string exit_command::process() {
    throw exit_exception();
}

exit_command::~exit_command() {};