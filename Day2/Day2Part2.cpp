//
// Created by leach on 11/17/2021.
//

#include "Day2Part2.h"

void DayTwoP2::parsePuzzle() {
    parseInput();
    printInput();
    printKeypad();
    std::pair<int, int> potential = position;
    for (auto& l : input ) {
        for (auto& c : l) {
            potential = position;
            if (c == 'D') {
                potential.first++;
            } else if (c == 'R') {
                potential.second++;
            } else if (c == 'L') {
                potential.second--;
            } else if (c == 'U') {
                potential.first--;
            }
            if (checkNeighbor(potential)) {
                position = potential;
            }
        }
        output.push_back(keypad[position.first][position.second]);
    }
    fmt::print("\n\n");
    for (auto& c : output) {
        fmt::print("{}", c);
    }
    fmt::print("\n");
}
bool DayTwoP2::checkNeighbor(std::pair<int, int> address) {
    if (address.first >= 0 && address.first < keypad.size()) {
        if (address.second >= 0 && address.second < keypad[address.first].size()) {
            if (keypad[address.first][address.second] != 'X') {
                return true;
            }
        }
    }
    return false;
}