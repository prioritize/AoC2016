cmake_minimum_required(VERSION 3.20)
project(AoC2016)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(GoogleTests)
add_subdirectory(fmt)
add_executable(AoC2016 main.cpp GoogleTests/tests.cpp OpenFile.cpp OpenFile.h DayOne.cpp DayOne.h DayTwo.cpp DayTwo.h)
