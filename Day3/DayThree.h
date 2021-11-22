//
// Created by leach on 11/20/2021.
//

#ifndef AOC2016_DAYTHREE_H
#define AOC2016_DAYTHREE_H
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include "fmt/core.h"
#include <algorithm>

struct Entry {
    std::vector<int> vals{0, 0, 0};
};
class DayThree {
public:
    std::string fname;
    std::vector<Entry> input;
    std::regex c;
    explicit DayThree(std::string fname); // : fname(std::move(fname)){}
    void parseRegex(std::vector<std::string> temp);
    void countTriangles();
    std::vector<std::string> parseInput();
    void sortEntry();
    bool possibleTriangle();
    void printInput();
};


#endif //AOC2016_DAYTHREE_H
