//
// Solutions for 2nd day of the 2016 Advent of Code.
//

#include "DayTwo.h"
void DayTwo::printKeypad() {
    fmt::print("{}", keypad[0][0]);
}
void DayTwo::parseInput() {
    std::ifstream inFile(fname);
    if (!inFile.is_open()) {
        fmt::print("{} is not open. exiting", fname);
        exit(1);
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string line;
    while (getline(buffer, line)) {
        input.push_back(line);
    }
}
void DayTwo::printInput() {
    for (auto& l : input) {
        fmt::print("{}\n", l);
    }
}
void DayTwo::parsePuzzle() {
    fmt::print("The size of keypad is ({}, {})\n", keypad.size(), keypad[0].size());
    for (auto& l : input) {
        for (auto &c: l) {
            if (c == 'D') {
                fmt::print("found a D\n");
                if (position.second < keypad.size()) {
                    position.second++;
                }
            } else if (c == 'U') {
                fmt::print("found a U\n");
                if (position.second > 0) {
                    position.second--;
                }
            } else if (c == 'R') {
                fmt::print("found a R\n");
                if (position.first < keypad[0].size()) {
                    position.first++;
                }
            } else if (c == 'L') {
                fmt::print("found a L\n");
                if (position.first > 0) {
                    position.first--;
                }
            } else {
                fmt::print("Caught something else\n");
            }
        }
        fmt::print("{}, {}", position.first, position.second);
        output.push_back(keypad[position.first][position.second]);
    }
    for (auto& c : output)  {
        fmt::print("{}", c);
    }
}