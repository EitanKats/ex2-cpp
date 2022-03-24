//
// Created by Eitan Kats on 20/03/2022.
//
#include "string"
#include "unordered_map"
#include "set"
#include "Direction.hpp"
#include "Page.hpp"

#ifndef EX2_CPP_NOTEBOOK_HPP
#define EX2_CPP_NOTEBOOK_HPP

using ariel::Direction;
using std::string;
using std::unordered_map;
using std::set;

namespace ariel {


    static const char eraseCharacter = '~';

    class Notebook {
    private:

        unordered_map<int, Page> pageMap;


        Page &getPage(int const &pageNum);

        void validateAccessParameters(int const &pageNum, int const &rowNum, int const &colNum) {
            if (pageNum < 0 || rowNum < 0 || colNum < 0) throw ("Negative access parameter was provided");
        }

        void validateAccessParameters(int const &pageNum) {
            if (pageNum < 0) throw ("Negative access parameter was provided");
        }

        void validateWriteOperation(int const &pageNum, int const &rowNum, int const &colNum, Direction direction,
                                    string const &text);

        void validateReadOperation(int const &pageNum, int const &rowNum, int const &colNum, Direction direction,
                                   int const &bufferSize);

        void validateEraseOperation(int const &pageNum, int const &rowNum, int const &colNum, Direction direction,
                                    int const &bufferSize);

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
