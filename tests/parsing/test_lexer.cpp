#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "parsing/lexer.h"
#include "parsing/parser.h"

TEST_CASE("Lexer: простая команда") 
{
    lexer_t lx;
    auto tokens = lx.tokenize("echo hello world");

    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens[0] == "echo");
    REQUIRE(tokens[1] == "hello");
    REQUIRE(tokens[2] == "world");
}

TEST_CASE("Lexer: кавычки объединяют токен") 
{
    lexer_t lx;
    auto tokens = lx.tokenize("echo \"hello world\"");

    REQUIRE(tokens.size() == 2);
    REQUIRE(tokens[0] == "echo");
    REQUIRE(tokens[1] == "hello world");
}

TEST_CASE("Lexer: смешанные кавычки") 
{
    lexer_t lx;
    auto tokens = lx.tokenize("echo 'a b' \"c d\"");

    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens[0] == "echo");
    REQUIRE(tokens[1] == "a b");
    REQUIRE(tokens[2] == "c d");
}

TEST_CASE("Lexer: несколько пробелов") 
{
    lexer_t lx;
    auto tokens = lx.tokenize("   pwd     ");

    REQUIRE(tokens.size() == 1);
    REQUIRE(tokens[0] == "pwd");
}