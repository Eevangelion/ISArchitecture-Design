#include <catch2/catch_test_macros.hpp>
#include "command/grep.h"
#include <fstream>

TEST_CASE("grep basic search in file", "[grep]") {
    std::ofstream f("test.txt");
    f << "Hello\nWorld\nHELLO\nEnd\n";
    f.close();

    grep_command_t g({"HELLO", "test.txt"});
    auto res = g.process();
    REQUIRE(res == "HELLO\n");
}

TEST_CASE("grep -i case-insensitive in file", "[grep]") {
    std::ofstream f("test.txt");
    f << "Hello\nWorld\nHELLO\n";
    f.close();

    grep_command_t g({"-i", "hello", "test.txt"});
    auto res = g.process();
    REQUIRE(res == "Hello\nHELLO\n");
}

TEST_CASE("grep -w whole word in file", "[grep]") {
    std::ofstream f("test.txt");
    f << "cat\nconcatenate\ncatapult\n";
    f.close();

    grep_command_t g({"-w", "cat", "test.txt"});
    auto res = g.process();
    REQUIRE(res == "cat\n");
}

TEST_CASE("grep -A 1 context lines in file", "[grep]") {
    std::ofstream f("test.txt");
    f << "a\nb\nc\nb\nx\n";
    f.close();

    grep_command_t g({"-A", "1", "b", "test.txt"});
    auto res = g.process();
    REQUIRE(res == "b\nc\nb\nx\n");
}

TEST_CASE("grep reads from pipeline argument (case-insensitive)", "[grep][pipe]") {
    grep_command_t g({"-i", "user"});
    g.add_argument("/Users/aleksandra/LongInt/1.txt\n/tmp/data\n");
    auto res = g.process();
    REQUIRE(res == "/Users/aleksandra/LongInt/1.txt\n");
}

TEST_CASE("grep -A 1 works on piped input", "[grep][pipe]") {
    grep_command_t g({"-A", "1", "b"});
    g.add_argument("a\nb\nc\nb\nx\n");
    auto res = g.process();
    REQUIRE(res == "b\nc\nb\nx\n");
}

TEST_CASE("grep -w works on piped input", "[grep][pipe]") {
    grep_command_t g({"-w", "main"});
    g.add_argument("int main()\nint domain()\n");
    auto res = g.process();
    REQUIRE(res == "int main()\n");
}

TEST_CASE("grep simple regex on piped input", "[grep][pipe]") {
    grep_command_t g({"^[A-Z]"});
    g.add_argument("apple\nBanana\ncherry\nDOG\n");
    auto res = g.process();
    REQUIRE(res == "Banana\nDOG\n");
}
