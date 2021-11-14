//
// Created by leach on 11/13/2021.
//

#ifndef AOC2016_DAYTWO_H
#define AOC2016_DAYTWO_H
#include <string>
#include <vector>
#include "fmt/core.h"

using std::vector;

class DayTwo {
public:
    explicit DayTwo(std::string fname) : fname(std::move(fname)), keypad({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) {}
    void printKeypad();
private:
    vector<vector<int>> keypad;
    std::string fname;
};


#endif //AOC2016_DAYTWO_H
