//
// Created by Eitan Kats on 21/03/2022.
//
#include "Notebook.hpp"
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
    Notebook::write(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                    string const &text) {

    }

    string Notebook::read(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                          unsigned int bufferSize) {

        unordered_map<unsigned int, unordered_map<unsigned int, vector<char>>>::iterator pageIter;

        pageIter = this->pageMap.find(pageNum);
        return "";
    }

    void Notebook::erase(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                         unsigned int bufferSize) {

    }

    void Notebook::show(unsigned int pageNum) {

        unordered_map<unsigned int, unordered_map<unsigned int, vector<char>>>::iterator pageIter;

        pageIter = this->pageMap.find(pageNum);

        if (pageIter != this->pageMap.end()) {
            std::cout << "";
        }
    }

}