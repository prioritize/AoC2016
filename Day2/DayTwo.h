//
// Created by leach on 11/13/2021.
//

#ifndef AOC2016_DAYTWO_H
#define AOC2016_DAYTWO_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "fmt/core.h"

using std::vector;

class DayTwo {
public:
    vector<vector<char>> keypad;
    std::pair<int, int> position;
    std::string fname;
    vector<std::string> input;
    vector<char> output;
    explicit DayTwo(std::string fname) :
        fname(std::move(fname)), keypad({{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}),
        position({1, 1}) {
    }

    void printKeypad();
    void parseInput();
    void printInput();
    void parsePuzzle();
    void setKeypad(std::vector<std::vector<char>> kPad);
};


#endif //AOC2016_DAYTWO_H
