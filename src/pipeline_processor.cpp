#include "pipeline_processor.h"

#include <string> 
#include <vector>
#include <memory>
#include <stdexcept>

std::string pipeline_processor_t::process_commands(std::vector<std::unique_ptr<command_t>> const& commands) {
    if (commands.empty()) {
        throw std::runtime_error("No commands found.");
    }
    std::string res = commands[0]->process();
    if (commands.size() > 1) {
        for (int i = 1; i < commands.size()-1; i++) {
            commands[i]->add_argument(res);
            res = commands[i]->process();
        }
    }
    return res;
};