#include "parsing/lexer.h"

#include <iterator>
#include <string>

lexer_t::lexer_t()
{
}

lexer_t::~lexer_t()
{
}

std::vector<std::string> lexer_t::tokenize(std::string const& input) const
{
    std::vector<std::string> tokens;
    bool in_quotes = false;
    char quote_char = '\0';
    std::string current;
    for (auto const& c : input)
    {
        if ((c == '"') || (c == '\''))
        {
            if (!in_quotes)
            {
                in_quotes = true;
                quote_char = c;
            }
            else if (quote_char == c)
            {
                in_quotes = false;
                quote_char = '\0';
            }
            else
            {
                current += c;
            }
        }
        else if (std::isspace((unsigned char)c) && !in_quotes)
        {
            if (!current.empty())
                tokens.emplace_back(std::move(current));
        }
        else
        {
            current += c;
        }
    }

    if (!current.empty())
        tokens.emplace_back(std::move(current));

    if (in_quotes)
        throw std::runtime_error("invalid input!");

    return tokens;
}
