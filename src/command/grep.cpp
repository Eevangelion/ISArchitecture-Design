#include "command/grep.h"
#include "error_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cxxopts.hpp>

grep_command_t::grep_command_t(const std::vector<std::string>& args) 
{
    try 
    {
        cxxopts::Options options("grep", "Search for patterns in files");
        options.allow_unrecognised_options();
        options.add_options()
            ("i,ignore_case", "Ignore case", cxxopts::value<bool>()->default_value("false"))
            ("w,word_match", "Match whole words", cxxopts::value<bool>()->default_value("false"))
            ("A", "Print N lines after match", cxxopts::value<int>()->default_value("0"))
            ("pattern", "Regex pattern", cxxopts::value<std::string>())
            ("file", "File to read", cxxopts::value<std::string>());

        options.parse_positional({"pattern", "file"});

        std::vector<const char*> argv;
        argv.push_back("grep");
        for (const auto& a : args) {
            argv.push_back(a.c_str());
        }

        auto result = options.parse(static_cast<int>(args.size() + 1), argv.data());

        if (result.count("pattern")) {
            pattern_ = result["pattern"].as<std::string>();
        } else {
            error_handler_t::get_instance().throw_error(error_handler_t::error_type::ARGUMENTS_INVALID_EXCEPTION, "grep: argument parsing error: no search pattern is provided");
        }
        if (result.count("file")) {
            filename_ = result["file"].as<std::string>();
        } else {
            error_handler_t::get_instance().throw_error(error_handler_t::error_type::ARGUMENTS_INVALID_EXCEPTION, "grep: argument parsing error: no filename is provided");
        }
        ignore_case_ = result["i"].as<bool>();
        word_match_  = result["w"].as<bool>();
        after_lines_ = result["A"].as<int>();

    }
    catch (const std::exception& e) 
    {   
        error_handler_t::get_instance().throw_error(error_handler_t::error_type::ARGUMENTS_INVALID_EXCEPTION, "grep: argument parsing error: " + *e.what());
    }
}

std::vector<std::string> grep_command_t::read_lines() const 
{
    std::vector<std::string> lines;
    std::string line;

    if (!filename_.empty()) 
    {
        std::ifstream file(filename_);
        if (!file.is_open())
            error_handler_t::get_instance().throw_error(error_handler_t::error_type::FILE_NOT_FOUND_EXCEPTION, "File " + filename_ + " does not exist.");
        while (std::getline(file, line))
            lines.push_back(line);
    } 
    else 
    {
        while (std::getline(std::cin, line))
            lines.push_back(line);
    }
    return lines;
}

std::string grep_command_t::process() const
{
    std::vector<std::string> lines;
    if (!get_arguments().empty()) 
    {
        std::string const& piped_input = get_arguments().back();
        std::istringstream iss(piped_input);
        std::string line;
        while (std::getline(iss, line))
            lines.push_back(line);
    } 
    else 
    {
        lines = read_lines();
    }
    std::ostringstream out;

    std::regex_constants::syntax_option_type flags = std::regex::ECMAScript;
    if (ignore_case_)
        flags |= std::regex::icase;

    std::string expr = pattern_;
    if (word_match_)
        expr = "\\b" + pattern_ + "\\b";

    std::regex rgx(expr, flags);

    std::vector<bool> print(lines.size(), false);
    for (size_t i = 0; i < lines.size(); ++i) 
    {
        if (std::regex_search(lines[i], rgx)) 
        {
            for (size_t j = i; j < std::min(lines.size(), i + after_lines_ + 1); ++j)
                print[j] = true;
        }
    }

    for (size_t i = 0; i < lines.size(); ++i)
    {
        if (print[i])
            out << lines[i] << '\n';
    }

    return out.str();
}
