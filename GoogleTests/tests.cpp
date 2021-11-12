#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "../OpenFile.h"
#include "../DayOne.h"
#include <fmt/core.h>

TEST(Test_of_GTest, FirstTest) {
    OpenFile f("input.txt");
    std::vector<char> input = f.input();
    for (auto& c : input) {
        std::cout << c;
    }
    ASSERT_EQ(1, 1);
}

TEST(ParseInput, PrintParsedInput) {
    OpenFile f("input.txt");
    DayOne dayOne(f.input());
    auto input = dayOne.parseInput();
    for (auto& data : input) {
        fmt::print("{} {} -- ", data.direction, data.offset);
    }
}

TEST(Overall, EvaluateInput) {
    OpenFile f("input.txt");
    DayOne dayOne(f.input());
    fmt::print("The ending distance for this input is {}\n", dayOne.endingDistance());
}
