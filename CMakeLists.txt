cmake_minimum_required(VERSION 3.16)
project(projects)


add_subdirectory(googletest)
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra \
        -Wpedantic -fomit-frame-pointer -fsanitize=address,leak,undefined \
         -g -std=c++17")

enable_testing()
add_executable(project main.cpp Graph.cpp StringFunctins.cpp Solver.cpp)
target_link_libraries(
        bonus1
        gtest
        gtest_main
)
add_executable(tests tests.cpp Graph.cpp StringFunctions.cpp Solver.cpp)
target_link_libraries(
        tests
        gtest
        gtest_main
)
add_test(NAME unit
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/tests
        )