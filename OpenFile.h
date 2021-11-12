#ifndef AOC2016_OPENFILE_H
#define AOC2016_OPENFILE_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using std::fstream;
using std::string;
class OpenFile {
private:
    std::vector<char> _input;
public:
    std::vector<char> input();

    explicit OpenFile(const string& fname) {
        std::ifstream inFile(fname);
        if (!inFile.is_open()) {
            std::cout << "File not open\n";
        }
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        string line;
        while(getline(buffer, line)) {
            for (auto &c : line)
            _input.push_back(c);
        }

    }
};


#endif //AOC2016_OPENFILE_H
