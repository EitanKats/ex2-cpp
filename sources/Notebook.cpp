//
// Created by Eitan Kats on 21/03/2022.
//
#include "Notebook.hpp"
#include "Page.hpp"
#include <vector>
#include "unordered_map"
#include "set"
#include <iostream>
#include <cctype>

using std::unordered_map;
using std::vector;
using std::set;
using std::cout;
using std::endl;
using std::isspace;
using std::isprint;
namespace ariel {

    Page &Notebook::getPage(int pageNum) {
        unordered_map<int, Page>::iterator pageIter = this->pageMap.find(pageNum);

        if (pageIter == this->pageMap.end()) {
            this->pageMap[pageNum] = Page();
            return this->pageMap[pageNum];
        }
        Page &chosenPage = pageIter->second;
        return chosenPage;
    }

    void validateBufferParams(Direction direction, int colNum, int bufferSize) {
        unsigned long totalTextSpace = (unsigned int) bufferSize + (unsigned int) colNum;
        if (bufferSize < 0) {
            throw ("Buffer value is bad");
        }
        if (direction == Direction::Horizontal) {
            if (totalTextSpace > lineLength || totalTextSpace < 0) {
                throw ("Buffer value is bad, should be positive and not pass 100 with respect to column number");
            }
        }

    }

    void
    Notebook::validateWriteOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                     string const &text) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);


        validateBufferParams(direction, colNum, text.size());


        for (char const &c: text) {
            bool isIllegalBlankChar = ((bool) isspace(c) && c != ' ');
            if (c == '\0' || isIllegalBlankChar || !(bool) isprint(c) || c == eraseCharacter) {
                throw ("illegal Character");
            }
        }
    }

    void Notebook::validateReadOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                         int bufferSize) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);


        validateBufferParams(direction, colNum, bufferSize);


    }

    void Notebook::validateEraseOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                          int bufferSize) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);


        validateBufferParams(direction, colNum, bufferSize);


    }

    void
    Notebook::write(int pageNum, int rowNum, int colNum, Direction direction,
                    string const &text) {
        validateWriteOperation(pageNum, rowNum, colNum, direction, text);

        getPage(pageNum).write(rowNum, colNum, direction, text);
    }

    string Notebook::read(int pageNum, int rowNum, int colNum, Direction direction,
                          int bufferSize) {
        validateReadOperation(pageNum, rowNum, colNum, direction, bufferSize);

        return getPage(pageNum).read(rowNum, colNum, direction, bufferSize);
    }

    void Notebook::erase(int pageNum, int rowNum, int colNum, Direction direction,
                         int bufferSize) {
        validateEraseOperation(pageNum, rowNum, colNum, direction, bufferSize);
        return getPage(pageNum).erase(rowNum, colNum, direction, bufferSize);
    }

    void Notebook::show(int pageNum) {

        Notebook::validateAccessParameters(pageNum);
        getPage(pageNum).show();
    }

}