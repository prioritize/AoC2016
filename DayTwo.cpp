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
    for (auto& l : input) {
        for (auto& c : l) {
            if (c == 'D') {
                if (position.first < keypad.size()-1) {
                    position.first++;
                }
            } else if (c == 'R') {
                if (position.second < keypad[0].size()-1) {
                    position.second++;
                }
            } else if (c == 'L') {
                if (position.second > 0) {
                    position.second--;
                }
            } else if (c == 'U') {
                if (position.first > 0) {
                    position.first--;
                }
            }
        }
        output.push_back(keypad[position.first][position.second]);
    }
    for (auto& c : output)  {
        fmt::print("{}", c);
    }
}
//explicit DayTwo(std::string fname) :
//fname(std::move(fname)), keypad({
//                                        {'X', 'X', '1', 'X', 'X'},
//                                        {'X', '2', '3', '4', 'X'},
//                                        {'5', '6', '7', '8', '9'},
//                                        {'X', 'A', 'B', 'C', 'X'},
//                                        {'X', 'X', 'D', 'X', 'X'}}),
//position({1, 1}) {}