//
// Created by leach on 11/17/2021.
//

#ifndef AOC2016_DAYTWOP2_H
#define AOC2016_DAYTWOP2_H
#include "DayTwo.h"

class DayTwoP2 : public  DayTwo {
public:
    explicit DayTwoP2(std::string (fname), std::vector<std::vector<char>> keypad, std::pair<int, int> start) :
    DayTwo(fname){
        position = start;
        this->fname = std::move(fname);
        this->keypad = std::move(keypad);
    }
    void parsePuzzle();
    bool checkNeighbor(std::pair<int, int> address);
};


#endif //AOC2016_DAYTWOP2_H
