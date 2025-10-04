#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "parsing/lexer.h"
#include "parsing/parser.h"
#include "error_handler.h"

TEST_CASE("Parser: много ковычек") 
{
    lexer_t lx;
    REQUIRE_THROWS_AS(lx.tokenize("echo '''a b 'ab'' \"c d\"'"), error_handler_t::error_type::INVALID_INPUT_EXCEPTION);
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
