cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
project(TicTacToe)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_library(includes src/ExampleClass.cpp
            include/Move.hpp
            include/IBoard.hpp
            include/PlayableBoard.hpp
            src/PlayableBoard.cpp)
target_include_directories(includes PUBLIC include)

add_executable(TicTacToe src/main.cpp)
target_link_libraries(TicTacToe includes)
target_compile_features(TicTacToe PUBLIC cxx_std_20)

add_executable(testing src/tests/ExampleTest.cpp
                        src/tests/BoardTesting.cpp
                        src/tests/MoveTesting.cpp)
target_link_libraries(testing
    gtest
    gmock
    gtest_main
    includes)
target_compile_features(testing PUBLIC cxx_std_20)
target_include_directories(testing PUBLIC include)
target_compile_options(testing PUBLIC -Wall -Wextra -pedantic -Werror)

add_custom_target(run_tests COMMAND ./testing DEPENDS testing)

enable_testing()

add_test(
    NAME allTests
    COMMAND testing
)