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

        unordered_map<unsigned int, unordered_map<unsigned int, vector<char>>> pageMap;
        unordered_map<unsigned int, set<unsigned int>> rowsMapping;
        set<unsigned int> availablePages;

    public:
        Notebook();

        void
        write(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction, string const &text);

        string read(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                    unsigned int bufferSize);

        void erase(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                   unsigned int bufferSize);

        void show(unsigned pageNum);

    };
}

#endif //EX2_CPP_NOTEBOOK_HPP
