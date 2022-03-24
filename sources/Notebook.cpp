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

    void validateHorizontalBufferParams(int colNum, size_t const &bufferSize) {
        unsigned long totalTextSpace = (unsigned int) bufferSize + (unsigned int) colNum;
        if (totalTextSpace > 100) {
            throw ("total buffer is bigger than 100");
        }
    }

    void
    Notebook::validateWriteOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                     string const &text) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);

        if (direction == Direction::Horizontal) {
            validateHorizontalBufferParams(colNum, text.size());
        }

        for (char const &c: text) {
            if (c == emptySpotChar || c == '\0' || (bool) isspace(c) || !(bool) isprint(c))
                throw ("illegal Character");
        }
    }

    void Notebook::validateReadOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                         int bufferSize) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);
        if (direction == Direction::Horizontal) {
            validateHorizontalBufferParams(colNum, (unsigned long) &bufferSize);
        }
    }

    void Notebook::validateEraseOperation(int pageNum, int rowNum, int colNum, Direction direction,
                                          int bufferSize) {
        Notebook::validateAccessParameters(pageNum, rowNum, colNum);
        if (direction == Direction::Horizontal) {
            validateHorizontalBufferParams(colNum, (unsigned long) &bufferSize);
        }
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

        unordered_map<int, Page>::iterator pageIter;
        pageIter = this->pageMap.find(pageNum);
        return "";
    }

    void Notebook::erase(int  pageNum, int  rowNum, int  colNum, Direction direction,
                         int  bufferSize) {

    }

    void Notebook::show(int  pageNum) {

        Notebook::validateAccessParameters(pageNum);
        unordered_map<int, Page>::iterator pageIter;

        pageIter = this->pageMap.find(pageNum);

        if (pageIter != this->pageMap.end()) {
            std::cout << "";
        }
    }

}