#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp> 

#include "../include/parsing/lexer.h"
#include "../include/parsing/parser.h"

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

TEST_CASE("Parser: много ковычек") 
{
    lexer_t lx;
    REQUIRE_THROWS_AS(lx.tokenize("echo '''a b 'ab'' \"c d\"'"), std::runtime_error);
}

TEST_CASE("Lexer: несколько пробелов") 
{
    lexer_t lx;
    auto tokens = lx.tokenize("   pwd     ");

    REQUIRE(tokens.size() == 1);
    REQUIRE(tokens[0] == "pwd");
}

TEST_CASE("Parser: простая команда с аргами") 
{
    lexer_t lx;
    parser_t ps;

    auto tokens = lx.tokenize("echo hello world");
    auto cmds = ps.parse(tokens);

    REQUIRE(cmds.size() == 1); // одна команда
    // Когда появятся реализации команд — можно проверять тип через dynamic_cast
}

TEST_CASE("Parser: пустой ввод") 
{
    parser_t ps;
    auto cmds = ps.parse({});
    REQUIRE(cmds.empty());
}
