#include "command/command.h"

command::command() {}

void command::add_argument(std::string arg) {
    arguments.push_back(arg);
}

std::string command::read_file(std::string& name) {
    // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    auto size = std::filesystem::file_size(name);
    std::string content(size, '\0');
    std::ifstream in(name);
    in.read(&content[0], size);
    return content;
}

bool command::is_file_exists(std::string& name) {
    // https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exists-using-standard-c-c11-14-17-c
    struct stat buffer;   
    return (stat (name.c_str(), &buffer) == 0); 
}
