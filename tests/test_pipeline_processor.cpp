#include "command/command.h"
#include "command/cat.h"
#include "command/pwd.h"
#include "command/exit.h"
#include "command/echo.h"
#include "command/wc.h"
#include "pipeline_processor.h"

#include <vector>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Single command") 
{
    pipeline_processor_t pp;
    std::vector<std::unique_ptr<command_t>> cmds;

    cat_command_t cat_cmd;
    cat_cmd.add_argument("./tests/command/test_filedata/1.txt");
    cmds.emplace_back(std::make_unique<cat_command_t>(cat_cmd));

    std::ifstream in("./tests/command/test_filedata/1.txt");
    std::stringstream buf;
    buf << in.rdbuf();
    std::string test = buf.str();
    
    REQUIRE(pp.process_commands(cmds) == test);
};

// TEST_CASE("Two different commands") {

// };

// TEST_CASE("More than two commands") {

// };

