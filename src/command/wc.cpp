#include "command/wc.h"
#include <filesystem>
#include <stdexcept>

wc_command_t::wc_command_t(std::vector<std::string> const& arguments) 
    : file_command_t(arguments)
{
}

wc_command_t::~wc_command_t() 
{
}

std::string wc_command_t::process() const {
    std::string result;
    int lines_count = 0, words_count = 0, bytes_count = 0;
    bool words_start;

    for (auto& arg : get_arguments()) {
        if (!is_file_exists(arg))
            throw std::runtime_error("File " + arg + " does not exist.");
        words_start = false;
        for (char& c : read_file(arg)) {
            switch (c) {
            case '\t':case ' ': {
                words_count += words_start;
                words_start = false;
                break;
            }
            case '\n':case '\r\n': {
                ++lines_count;
                words_count += words_start;
                words_start = false;
                break;
            }
            default: {
                words_start = true;
                break;
            }
            }
        }
        words_count += words_start;
        bytes_count += std::filesystem::file_size(arg);
    }
    result += std::to_string(lines_count) + " " + std::to_string(words_count) + " " + std::to_string(bytes_count);
    return result;
}