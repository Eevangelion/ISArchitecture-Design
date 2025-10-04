#include "environment.h"
#include "parsing/lexer.h"
#include "error_handler.h"

#include <string>
#include <stdexcept>

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

    auto get_variable = [](std::string const& token)
    {
        std::string norm_token;
        for (size_t i = 0; i < token.size(); ++i) 
        {
            if (token[i] == '$') 
            {
                size_t j = i + 1;
                std::string name;
                while (j < token.size() && (std::isalnum((unsigned char)token[j]) || token[j] == '_'))
                    name += token[j++];

                if (!name.empty()) 
                {
                    norm_token += environment_t::get_instance().get_variable(name);
                    i = j - 1;
                } 
                else 
                {
                    norm_token += '$';
                }
            } 
            else 
            {
                norm_token += token[i];
            }
        }
        
        return norm_token;
    };

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
            {
                tokens.emplace_back(get_variable(current));
                current.clear();
            }
        }
        else if (c == '|' && !in_quotes)
        {
            if (!current.empty()) 
            {
                tokens.emplace_back(get_variable(current));
                current.clear();
            }
            tokens.emplace_back("|");
        }
        else
        {
            current += c;
        }
    }

    if (!current.empty())
        tokens.emplace_back(get_variable(current));

    if (in_quotes) {
        error_handler_t& error_handler = error_handler_t::get_instance();
        error_handler.throw_error(error_handler_t::error_type::INVALID_INPUT_EXCEPTION, "Invalid quote input");
    }
    return tokens;
}
