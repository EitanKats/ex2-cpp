//
// Created by Eitan Kats on 21/03/2022.
//
#include "Notebook.hpp"
#include "Page.hpp"
#include <vector>
#include "unordered_map"
#include "set"
#include <iostream>

using std::unordered_map;
using std::vector;
using std::set;
using std::cout;
using std::endl;
namespace ariel {

    void
    Notebook::write(int pageNum, int rowNum, int colNum, Direction direction,
                    string const &text) {

    }

    string Notebook::read(int pageNum, int rowNum, int colNum, Direction direction,
                          int bufferSize) {

        unordered_map<int, Page>::iterator pageIter;

        pageIter = this->pageMap.find(pageNum);
        return "";
    }

    void Notebook::erase(int pageNum, int rowNum, int colNum, Direction direction,
                         int bufferSize) {

    }

    void Notebook::show(int pageNum) {

        unordered_map<int, Page>::iterator pageIter;

        pageIter = this->pageMap.find(pageNum);

        if (pageIter != this->pageMap.end()) {
            std::cout << "";
        }
    }

}