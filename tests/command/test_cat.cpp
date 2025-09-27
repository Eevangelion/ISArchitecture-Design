#include "command/cat.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <catch2/catch_test_macros.hpp>

std::vector<std::string> filepaths = {"tests/command/test_filedata/1.txt", "tests/command/test_filedata/2"};


TEST_CASE("Reading single file from relative path"){
    cat_command_t cmd;
    cmd.add_argument(filepaths[0]);

    std::ifstream in(filepaths[0]);
    std::stringstream buf;
    buf << in.rdbuf();
    std::string test = buf.str();

    REQUIRE(cmd.process() == test);
}

TEST_CASE("Reading multiple files from relative path"){
    cat_command_t cmd;
    std::stringstream buf;

    for (std::string &path : filepaths){
        cmd.add_argument(path);

        std::ifstream in(path);
        buf << in.rdbuf();
        in.close();
    }

    std::string test = buf.str();

    REQUIRE(cmd.process() == test);
}

TEST_CASE("Reading single file from absolute path"){
    cat_command_t cmd;
    std::string abs_path = std::filesystem::current_path().string() + '/' + filepaths[0];
    cmd.add_argument(abs_path);

    std::ifstream in(abs_path);
    std::stringstream buf;
    buf << in.rdbuf();
    std::string test = buf.str();

    REQUIRE(cmd.process() == test);
}

TEST_CASE("Reading multiple files from absolute path"){
    cat_command_t cmd;
    std::string abs_path;
    std::stringstream buf;
    for (std::string path : filepaths) {
        abs_path = std::filesystem::current_path().string() + '/' + path; 
        cmd.add_argument(abs_path);

        std::ifstream in(path);
        buf << in.rdbuf();
    }

    std::string test = buf.str();

    REQUIRE(cmd.process() == test);
}

TEST_CASE("Reading from non-existent files"){
    cat_command_t cmd;
    cmd.add_argument("gibberish");
    REQUIRE_THROWS_AS(cmd.process(), std::runtime_error);
}