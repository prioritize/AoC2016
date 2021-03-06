#include "DayOne.h"
#include <regex>
#include <iostream>
#include <string>
#include "fmt/core.h"

int DayOne::endingDistance() {
    auto moves = parseInput();
    for (auto& m : moves) {
        nextDirection(m);
        generatePath(m);
        calcOffset(m);
//        std::pair<int, int> loc(pos.x, pos.y);
//        if (visited.contains(loc)) {
//            fmt::print("{}, {} is the first location we visit twice. It is {} blocks away", pos.x, pos.y, abs(pos.x) + abs(pos.y));
//            return abs(pos.x) + abs(pos.y);
//        } else {
//            visited.insert({loc, true});
//        }
    }
    return abs(pos.x) + abs(pos.y);
}

// Parse the input here into a vector of moves
vector<Move> DayOne::parseInput() {
    vector<Move> out;
    std::regex c("[RL][0-9]*");
    std::string in(this->_input.begin(), this->_input.end());
    std::sregex_iterator currentMatch(in.begin(), in.end(), c);
    std::sregex_iterator lastMatch;
    while (currentMatch != lastMatch) {
        std::smatch match = *currentMatch;
        if (match.ready()) {
            std::string temp(match[0]);
            out.push_back({temp[0], stoi(temp.substr(1, temp.length()-1))});
        }
        currentMatch++;
    }
    return out;
}

void DayOne::nextDirection(Move& m) {
    switch (m.direction) {
        case 'L':
            switch (current) {
                case 'N':
                    current = 'W';
                    break;
                case 'S':
                    current = 'E';
                    break;
                case 'E':
                    current = 'N';
                    break;
                case 'W':
                    current = 'S';
                    break;
            }
            break;
        case 'R':
            switch (current) {
                case 'N':
                    current = 'E';
                    break;
                case 'S':
                    current = 'W';
                    break;
                case 'E':
                    current = 'S';
                    break;
                case 'W':
                    current = 'N';
                    break;
            }
            break;
    }
}

void DayOne::calcOffset(Move& m) {
    switch (current) {
        case 'N':
            pos.y += m.offset;
            break;
        case 'S':
            pos.y -= m.offset;
            break;
        case 'E':
            pos.x += m.offset;
            break;
        case 'W':
            pos.x -= m.offset;
            break;
    }
}
void DayOne::generatePath(Move &m) {
    // I'm going to purposefully choose to ignore the direction and assume that it's been handled for me
    vector<std::pair<int, int>> steps;
    switch (current) {
        case 'N':
            for (int i = 1; i <= m.offset; ++i) {
                steps.push_back({pos.x, pos.y + i});
            }
            break;
        case 'S':
            for (int i = 1; i <= m.offset; ++i) {
                steps.push_back({pos.x, pos.y - i});
            }
            break;
        case 'E':
            for (int i = 1; i <= m.offset; ++i) {
                steps.push_back({pos.x + i, pos.y});
            }
            break;
        case 'W':
            for (int i = 1; i <= m.offset; ++i) {
                steps.push_back({pos.x - i, pos.y});
            }
            break;
    }
    for (auto& s : steps) {
        if (!visited.contains(s)) {
            visited.insert({s, true});
            fmt::print("inserting {}, {} into the visited map\n", s.first, s.second);
        }
        else {
            fmt::print("{}, {} is the first location we visit twice. It is {} blocks away", s.first, s.second, abs(s.first) + abs(s.second));
            return;
        }
    }
}