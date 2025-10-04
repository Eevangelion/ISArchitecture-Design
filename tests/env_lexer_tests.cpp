#include "../include/parsing/lexer.h"
#include "../include/environment.h"

#include <catch2/catch_all.hpp>

TEST_CASE("Environment: установка и получение переменной") {
    environment_t::get_instance().set_variable("USER", "bob");
    REQUIRE(environment_t::get_instance().get_variable("USER") == "bob");
}

TEST_CASE("Environment: пустое значение если переменной нет") {
    REQUIRE(environment_t::get_instance().get_variable("NOT_DEFINED").empty());
}

TEST_CASE("Environment: обновление существующей переменной") {
    auto& env = environment_t::get_instance();
    env.set_variable("VAR", "first");
    env.set_variable("VAR", "second");
    REQUIRE(env.get_variable("VAR") == "second");
}

TEST_CASE("Lexer: подстановка переменной окружения") {
    auto& env = environment_t::get_instance();
    env.set_variable("USER", "bob");

    lexer_t lx;
    auto tokens = lx.tokenize("echo $USER");
    REQUIRE(tokens.size() == 2);
    REQUIRE(tokens[1] == "bob");
}

TEST_CASE("Lexer: подстановка с подчёркиванием") {
    auto& env = environment_t::get_instance();
    env.set_variable("MY_VAR_1", "value");

    lexer_t lx;
    auto tokens = lx.tokenize("echo $MY_VAR_1");
    REQUIRE(tokens.size() == 2);
    REQUIRE(tokens[1] == "value");
}

TEST_CASE("Lexer: неизвестная переменная остаётся пустой") {
    auto& env = environment_t::get_instance();
    REQUIRE(env.get_variable("UNset_variable_VAR").empty());

    lexer_t lx;
    auto tokens = lx.tokenize("echo $UNset_variable_VAR");
    REQUIRE(tokens.size() == 2);
    REQUIRE(tokens[1].empty());
}

TEST_CASE("Lexer: пайп как отдельный токен") {
    lexer_t lx;
    auto tokens = lx.tokenize("cat file.txt | wc");

    REQUIRE(tokens.size() == 4);
    REQUIRE(tokens[0] == "cat");
    REQUIRE(tokens[1] == "file.txt");
    REQUIRE(tokens[2] == "|");
    REQUIRE(tokens[3] == "wc");
}

TEST_CASE("Lexer: комбинация окружения и пайпов") {
    auto& env = environment_t::get_instance();
    env.set_variable("FILE", "input.txt");

    lexer_t lx;
    auto tokens = lx.tokenize("cat $FILE | wc");
    REQUIRE(tokens.size() == 4);
    REQUIRE(tokens[1] == "input.txt");
    REQUIRE(tokens[2] == "|");
}
