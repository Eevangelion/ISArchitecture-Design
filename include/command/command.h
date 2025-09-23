#ifndef HW1_COMMAND_COMMAND_H_
#define HW1_COMMAND_COMMAND_H_

#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <filesystem>

class command {
private:
    std::vector<std::string> arguments;

    std::string read_file(std::string&);
    bool is_file_exists(std::string&);
public:
    command();
    void add_argument(std::string);
    virtual std::string process() = 0;
    virtual ~command() {}
};

#endif