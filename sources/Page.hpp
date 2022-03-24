//
// Created by Eitan Kats on 24/03/2022.
//
#include <vector>
#include "unordered_map"
#include "Direction.hpp"
#include "string"

using std::unordered_map;
using std::vector;
using std::string;
#ifndef EX2_CPP_PAGE_HPP
#define EX2_CPP_PAGE_HPP

namespace ariel {
    static const char emptySpotChar = '_';
    static const int lineLength = 100;

    class Page {
    private:
        unordered_map<int, vector<char>> rows;

        vector<char> &getRow(int const &rowNum);

    public:
        void write(int const &rowNum, int const &colNum, Direction direction,
                   string const &text);
    };
}


#endif //EX2_CPP_PAGE_HPP
