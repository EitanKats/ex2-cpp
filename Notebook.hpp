//
// Created by Eitan Kats on 20/03/2022.
//
#include "Direction.hpp"
#include "string"
#include <vector>
#include "map"

#ifndef EX2_CPP_NOTEBOOK_HPP
#define EX2_CPP_NOTEBOOK_HPP

using ariel::Direction;
using std::string;
using std::map;
using std::vector;

namespace ariel {

    static const int emptySpotChar = '_';
    static const int lineLength = 100;
    static const int eraseCharacter = '~';

    class Notebook {
    private:
        map<int, map<int, vector<char>>> *pageMap;
    public:
        Notebook();

        void write(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction, string text);

        string read(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                    unsigned int bufferSize);

        void erase(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                   unsigned int bufferSize);

        string show(int pageNum);

    };
}

#endif //EX2_CPP_NOTEBOOK_HPP
