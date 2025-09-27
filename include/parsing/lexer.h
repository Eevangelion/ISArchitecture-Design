#pragma once

#include <vector>
#include <string>

class lexer_t 
{
public:
    lexer_t();
    ~lexer_t();

    std::vector<std::string> tokenize(std::string const& input) const;
};