//
// Created by Eitan Kats on 20/03/2022.
//
#include "Direction.hpp"
#include "string"
#include <vector>
#include "unordered_map"
#include "set"

#ifndef EX2_CPP_NOTEBOOK_HPP
#define EX2_CPP_NOTEBOOK_HPP

using ariel::Direction;
using std::string;
using std::unordered_map;
using std::vector;
using std::set;

namespace ariel {

    static const char emptySpotChar = '_';
    static const int lineLength = 100;
    static const char eraseCharacter = '~';

    class Notebook {
    private:

        unordered_map<int, unordered_map<int, vector<char>>> pageMap;
        unordered_map<int, set<int>> rowsMapping;
        set<int> availablePages;

    public:
        void
        write(int pageNum, int rowNum, int colNum, Direction direction, string const &text);

        string read(int pageNum, int rowNum, int colNum, Direction direction,
                    int bufferSize);

        void erase(int pageNum, int rowNum, int colNum, Direction direction,
                   int bufferSize);

        void show(int pageNum);

    };
}

#endif //EX2_CPP_NOTEBOOK_HPP
