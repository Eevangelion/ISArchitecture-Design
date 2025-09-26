cmake_minimum_required(VERSION 3.14)
project(simple_interpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES 
    src/*.cpp 
    src/parsing/*.cpp)
# add_library(my_lib ${SRC_FILES})

set(TARGET_NAME "${PROJECT_NAME}")

add_executable(${TARGET_NAME} 
    ${SRC_FILES})

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(catch2)

add_executable(lexer_parser_tests 
    tests/lexer_parser_tests.cpp 
    src/parsing/lexer.cpp
    src/parsing/parser.cpp)
  
# target_include_directories(lexer_parser_tests PRIVATE include)
target_link_libraries(lexer_parser_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME lexer_parser_tests COMMAND lexer_parser_tests)