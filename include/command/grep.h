#pragma once

#include "command.h"

class grep_command_t : public command_t 
{
public:
    explicit grep_command_t(const std::vector<std::string>& args);
    std::string process() const override;

private: 
    std::vector<std::string> read_lines() const;

private:
    std::string pattern_;
    std::string filename_;
    bool ignore_case_ = false;
    bool word_match_ = false;
    int after_lines_ = 0;
};
