#include "command/cat.h"

std::string cat_command::process() {
    std::string result;
    for (std::string &path : this->arguments) {
        if (!this->is_file_exists(path)) {
            throw std::runtime_error("File " + path + " does not exist.");
        }
        result += this->read_file(path);
    };
    return result;
}