#include "pipeline_processor.h"

#include <string> 
#include <vector>
#include <memory>


std::string pipeline_processor_t::process_commands(std::vector<std::unique_ptr<command_t> > const& commands) 
{
    std::string res;
    if (!commands.empty())
        res = commands[0]->process();

    if (commands.size() > 1) 
    {
        for (size_t i = 1; i < commands.size() - 1; ++i) 
        {
            commands[i]->add_argument(res);
            res = commands[i]->process();
        }
    }

    return res;
};