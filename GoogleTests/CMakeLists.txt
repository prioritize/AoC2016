# Define the project name
project(GoogleTests)
# Define the location of the google tests library
add_subdirectory(include/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(GoogleTests tests.cpp ../OpenFile.cpp ../DayOne.cpp ../DayTwo.cpp ../DayTwo.h)
target_link_libraries(GoogleTests gtest gtest_main fmt::fmt)
