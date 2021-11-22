#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "../OpenFile.h"
#include "../Day1/DayOne.h"
#include "../Day2/DayTwo.h"
#include "../Day2/Day2Part2.h"
#include "../Day3/DayThree.h"
#include "../Day3/DayThreeP2.h"
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

TEST(Day2, TestConstructor) {
    DayTwo dayTwo("input2.txt");
    dayTwo.printKeypad();
}

TEST(Day2, TestInput) {
    DayTwo dayTwo("input2.txt");
    dayTwo.parseInput();
    dayTwo.printInput();
}
TEST(Day2, TestPart1) {
    DayTwo dayTwo("input2.txt");
    dayTwo.parseInput();
    dayTwo.parsePuzzle();
}
TEST(Day2P2, TestParsePuzzle) {
    std::vector<std::vector<char>> keypad =
            {
                    {'X', 'X', '1', 'X', 'X'},
                    {'X', '2', '3', '4', 'X'},
                    {'5', '6', '7', '8', '9'},
                    {'X', 'A', 'B', 'C', 'X'},
                    {'X', 'X', 'D', 'X', 'X'},
            };
    DayTwoP2 dayTwoP2("input2.txt", keypad, {2,2});
    dayTwoP2.parsePuzzle();
}
TEST(Day3P1, TestParseInput) {
    DayThree dayThree("input3.txt");
    dayThree.parseInput();
    dayThree.printInput();
}

TEST(Day3P1, TestCountTriangles) {
    DayThree dayThree("input3.txt");
    dayThree.parseRegex(dayThree.parseInput());
    dayThree.countTriangles();
}

TEST(Day3P2, TestCountTriangles) {
    DayThreeP2 dayThree("input3.txt");
    dayThree.parseRegexP2(dayThree.parseInput());
    dayThree.makeTriangles();
//    dayThree.countTriangles();
}

TEST(Day3P2, TestPrintParsedInput) {
    DayThreeP2 dayThree("input3.txt");
    dayThree.parseRegexP2(dayThree.parseInput());
    dayThree.makeTriangles();
    dayThree.printParsedInput();
    fmt::print("{}", dayThree.countTris());
}
