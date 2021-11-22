cmake_minimum_required(VERSION 3.20)
project(AoC2016)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(GoogleTests)
add_subdirectory(fmt)
add_executable(AoC2016 main.cpp GoogleTests/tests.cpp OpenFile.cpp OpenFile.h Day1/DayOne.cpp Day1/DayOne.h Day2/DayTwo.cpp Day2/DayTwo.h Day2/Day2Part2.cpp Day2/Day2Part2.h Day3/DayThree.cpp Day3/DayThree.h Day3/DayThreeP2.cpp Day3/DayThreeP2.h)
