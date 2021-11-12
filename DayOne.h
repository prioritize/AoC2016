//
// Created by leach on 11/10/2021.
//

#ifndef AOC2016_DAYONE_H
#define AOC2016_DAYONE_H
#include <vector>
#include <map>

using std::vector;
struct Move {
    char direction;
    int offset;
};
struct Position {
    int x = 0;
    int y = 0;
};

class DayOne {
private:
    vector<char> _input;
    Position pos;
    void nextDirection(Move& m);
    void calcOffset(Move& m);
    std::map<std::pair<int, int>, bool> visited;

public:
    explicit DayOne(vector<char> input) : _input(input), current('N'){
        visited.insert({{0, 0}, true});
    }
    char current;
    vector<Move> parseInput();
    int endingDistance();
};


#endif //AOC2016_DAYONE_H
