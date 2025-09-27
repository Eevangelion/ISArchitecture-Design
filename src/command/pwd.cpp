#include "command/pwd.h"

pwd_command::pwd_command() {};

std::string pwd_command::process() {
    return std::filesystem::current_path().string();
}

pwd_command::~pwd_command() {};