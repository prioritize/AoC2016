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
    explicit DayTwo(std::string fname) :
        fname(std::move(fname)), keypad({{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}),
        position({1, 1}) {}
    void printKeypad();
    void parseInput();
    void printInput();
    void parsePuzzle();
private:
    vector<vector<char>> keypad;
    vector<std::string> input;
    std::string fname;
    std::pair<int, int> position;
    vector<char> output;
};


#endif //AOC2016_DAYTWO_H
