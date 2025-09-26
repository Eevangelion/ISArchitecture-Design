#ifndef HW1_PARSING_LEXER_H_
#define HW1_PARSING_LEXER_H_

#include <vector>
#include <string>

class lexer_t 
{
public:
    lexer_t();
    ~lexer_t();

    std::vector<std::string> tokenize(std::string const& input) const;
};

#endif