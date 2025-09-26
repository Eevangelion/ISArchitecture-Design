#include "command/pwd.h"

std::string pwd_command::process() {
    return std::filesystem::current_path().string();
}