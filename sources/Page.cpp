//
// Created by Eitan Kats on 24/03/2022.
//
#include <Page.hpp>
#include <vector>
#include "string"

using std::vector;
using std::string;
namespace ariel {


    vector<char> &Page::getRow(int rowNum) {

        unordered_map<int, vector<char>>::iterator rowIter;
        rowIter = this->rows.find(rowNum);

        if (rowIter == this->rows.end()) {
            this->rows[rowNum] = vector<char>(lineLength, emptySpotChar);
            return this->rows[rowNum];
        }
        vector<char> &chosenRow = rowIter->second;
        return chosenRow;
    }

    void Page::write(int rowNum, int colNum, Direction direction, const std::string &text) {
        vector<char> &currRow = getRow(rowNum);
        unsigned int unsignedColNum = (unsigned int) colNum;
        if (direction == Direction::Horizontal) {
            for (string::size_type i = 0; i < text.size(); ++i) {
                char currCharacter = currRow.at(unsignedColNum + i);
                if (currCharacter == emptySpotChar) {
                    currRow.at(unsignedColNum + i) = text.at(i);
                } else {
                    throw ("Illegal write operation");
                }

            }
        }
    }

    string Page::read(int rowNum, int colNum, Direction direction, int bufferSize) {
        return "";
    }

}


