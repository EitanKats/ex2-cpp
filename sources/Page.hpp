//
// Created by Eitan Kats on 24/03/2022.
//
#include <vector>
#include "unordered_map"
#include "Direction.hpp"
#include "string"
#include "set"

using std::unordered_map;
using std::vector;
using std::string;
using std::set;
#ifndef EX2_CPP_PAGE_HPP
#define EX2_CPP_PAGE_HPP

namespace ariel {
    static const char emptySpotChar = '_';
    static const int lineLength = 100;
    static const char eraseCharacter = '~';

    class Page {
    private:
        unordered_map<int, vector<char>> rows;
        set<int> rowsWithText;


        vector<char> &getRow(int rowNum);

        void handleVerticalWrite(int rowNum, int colNum, const string &text);

        void handleHorizontalWrite(int rowNum, int colNum, const string &text);

        string handleVerticalRead(int rowNum, int colNum, int bufferSize);

        string handleHorizontalRead(int rowNum, int colNum, int bufferSize);

    public:
        void write(int rowNum, int colNum, Direction direction,
                   string const &text);

        string read(int rowNum, int colNum, Direction direction, int bufferSize);

        void erase(int rowNum, int colNum, Direction direction, int bufferSize);

        void show();
    };
}


#endif //EX2_CPP_PAGE_HPP
