cmake_minimum_required(VERSION 3.14)
project(SimpleInterpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(interpreter ${SRC_FILES})

# Тесты
list(FILTER SRC_FILES EXCLUDE REGEX ".*main\.cpp$")
add_library(my_lib ${SRC_FILES})

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(catch2)

file(GLOB_RECURSE TEST_FILES tests/*.cpp)
add_executable(interpreter_tests ${TEST_FILES})

file(COPY ${CMAKE_SOURCE_DIR}/tests/command/test_filedata/ 
     DESTINATION ${CMAKE_BINARY_DIR}/tests/command/test_filedata/)

target_link_directories(interpreter_tests PRIVATE include)
target_link_libraries(interpreter_tests PRIVATE my_lib Catch2::Catch2WithMain)

include(CTest)
include(Catch)
enable_testing()
catch_discover_tests(interpreter_tests)