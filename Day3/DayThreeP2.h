//
// Created by leach on 11/20/2021.
//

#ifndef AOC2016_DAYTHREEP2_H
#define AOC2016_DAYTHREEP2_H
#include "DayThree.h"

using std::vector;
class DayThreeP2 : public DayThree {
public:
    vector<vector<int>> vinput;
    vector<vector<int>> parsedInput;
    explicit DayThreeP2(std::string fname) : DayThree(std::move(fname)){}
    void parseRegexP2(std::vector<std::string> temp);
    void printInput();
    void makeTriangles();
    void printParsedInput();
    int countTris();
};



#endif //AOC2016_DAYTHREEP2_H
