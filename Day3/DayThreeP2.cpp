//
// Created by leach on 11/20/2021.
//

#include "DayThreeP2.h"
void DayThreeP2::parseRegexP2(std::vector<std::string> temp) {
    int matches = 0;
    for (auto& e : temp) {
        std::sregex_iterator currentMatch(e.begin(), e.end(), c);
        std::sregex_iterator lastMatch;
        std::smatch match = *currentMatch;
        if (match.ready()) {
            vinput.push_back({stoi(match[1]), stoi(match[2]), stoi(match[3])});
        } else {
            fmt::print("No match found\n");
        }
    }
}
void DayThreeP2::printInput() {
    for (auto& v : vinput) {
        fmt::print("{} {} {}\n", v[0], v[1], v[2]);
    }
}

// Reorder the input vector to rotate columns into sets of three triangles
void DayThreeP2::makeTriangles() {
    if (vinput.size() % 3 != 0) {
        fmt::print("Input vector size is not divisible by 3\n");
        exit(1);
    } else {
        fmt::print("Input vector size is divisible by 3\n");
    }
    for (int i = 0; i < vinput.size(); i += 3) {
        for (int j = 0; j < 3; j++) {
            vector<int> temp{vinput[i][j], vinput[i+1][j], vinput[i+2][j]};
            std::sort(temp.begin(), temp.end());
            parsedInput.push_back(temp);
        }
    }
}

void DayThreeP2::printParsedInput() {
    for (auto &v: parsedInput) {
        fmt::print("{} {} {}\n", v[0], v[1], v[2]);
    }
}

int DayThreeP2::countTris() {
    int count = 0;
    for (auto &v: parsedInput) {
        if (v[0] + v[1] > v[2]) {
            count++;
        }
    }
    return count;
}