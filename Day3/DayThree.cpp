//
// Created by leach on 11/20/2021.
//

#include "DayThree.h"

DayThree::DayThree(std::string fname) :fname(std::move(fname)){
    c = R"(\s*([0-9]{1,3})\s*([0-9]{1,3})\s*([0-9]{1,3})\s?)";
}

void DayThree::parseRegex(std::vector<std::string> temp) {
    for (auto& e : temp) {
        std::sregex_iterator currentMatch(e.begin(), e.end(), c);
        std::sregex_iterator lastMatch;
        std::smatch match = *currentMatch;
        if (match.ready()) {
            Entry t;
            t.vals[0] = stoi(match[1]);
            t.vals[1] = stoi(match[2]);
            t.vals[2] = stoi(match[3]);
            std::sort(t.vals.begin(), t.vals.end());
            input.push_back(t);
        } else {
            fmt::print("No match found\n");
        }
    }
}

std::vector<std::string> DayThree::parseInput() {
    std::ifstream inFile(fname);
    std::stringstream inBuffer;
    std::vector<std::string> tempInput;
    if(!inFile.is_open()) {
        fmt::print("{} is not open, exiting\n", fname);
        exit(1);
    }
    inBuffer << inFile.rdbuf();
    std::string temp;
    while (getline(inBuffer, temp)) {
        tempInput.push_back(temp);
    }
    return tempInput;
//    parseRegex(tempInput);
}
void DayThree::printInput() {
    for (auto& e : input) {
        fmt::print("{}, {}, {}\n", e.vals[0], e.vals[1], e.vals[2]);
    }
}

void DayThree::countTriangles() {
    int count = 0;
    for (auto& e : input) {
        if (e.vals[0] + e.vals[1] > e.vals[2]) {
            count++;
        }
    }
    fmt::print("{}\n", count);
}