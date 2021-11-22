# Define the project name
project(GoogleTests)
# Define the location of the google tests library
add_subdirectory(include/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(GoogleTests tests.cpp ../OpenFile.cpp ../Day1/DayOne.cpp ../Day2/DayTwo.cpp ../Day2/DayTwo.h ../Day2/Day2Part2.cpp ../Day2/Day2Part2.h ../Day3/DayThree.cpp ../Day3/DayThree.h ../Day3/DayThreeP2.cpp ../Day3/DayThreeP2.h)
target_link_libraries(GoogleTests gtest gtest_main fmt::fmt)
