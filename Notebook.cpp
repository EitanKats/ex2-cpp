//
// Created by Eitan Kats on 21/03/2022.
//
#include "Notebook.hpp"
#include <vector>
#include "map"
using std::map;
using std::vector;
namespace ariel {

    Notebook::Notebook() {
        this->pageMap = new map<int, map<int, vector<char>>>();
    }

    void
    Notebook::write(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction, string text) {

    }

    string Notebook::read(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                          unsigned int bufferSize) {
        return "";
    }

    void Notebook::erase(unsigned int pageNum, unsigned int rowNum, unsigned int colNum, Direction direction,
                         unsigned int bufferSize) {

    }

    string Notebook::show(int pageNum) {
        return "";
    }

}
