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

    void Page::handleVerticalWrite(int rowNum, int colNum, const string &text) {
        vector<char> &currRow = getRow(rowNum);
        for (string::size_type i = 0; i < text.size(); ++i) {
            char currCharacter = currRow.at((unsigned int) colNum + i);
            if (currCharacter == emptySpotChar || text.at(i) == eraseCharacter) {
                currRow.at((unsigned int) colNum + i) = text.at(i);
            } else {
                throw ("Illegal write operation");
            }
        }
    }

    void Page::handleHorizontalWrite(int rowNum, int colNum, const string &text) {
        for (string::size_type i = 0; i < text.size(); ++i) {
            vector<char> &currRow = getRow((unsigned int) rowNum + i);
            char currCharacter = currRow.at((unsigned int) colNum);
            if (currCharacter == emptySpotChar || text.at(i) == eraseCharacter) {
                currRow.at((unsigned int) colNum) = text.at(i);
            } else {
                throw ("Illegal write operation");
            }
        }
    }

    string Page::handleHorizontalRead(int rowNum, int colNum, int bufferSize) {
        string textResult = "";
        vector<char> &currRow = getRow(rowNum);
        for (int i = colNum; i < bufferSize; ++i) {
            char currCharacter = currRow.at((unsigned int) colNum + (unsigned int) i);
            textResult.append(1, currCharacter);
        }
        return textResult;
    }

    string Page::handleVerticalRead(int rowNum, int colNum, int bufferSize) {
        string textResult = "";

        for (int i = 0; i < bufferSize; ++i) {
            int nextRowIdx = rowNum + i;
            vector<char> &currRow = getRow(nextRowIdx);
            char currCharacter = currRow.at((unsigned int) colNum);
            textResult.append(1, currCharacter);
        }
        return textResult;
    }

    void Page::write(int rowNum, int colNum, Direction direction, const string &text) {
        if (direction == Direction::Horizontal) {
            handleVerticalWrite(rowNum, colNum, text);
        } else {
            handleHorizontalWrite(rowNum, colNum, text);
        }

    }

    string Page::read(int rowNum, int colNum, Direction direction, int bufferSize) {
        if (direction == Direction::Horizontal) {
            return handleHorizontalRead(rowNum, colNum, bufferSize);
        } else {
            return handleVerticalRead(rowNum, colNum, bufferSize);
        }
    }

    void Page::erase(int rowNum, int colNum, Direction direction, int bufferSize) {
        string eraseString = string((unsigned) bufferSize, eraseCharacter);
        write(rowNum, colNum, direction, eraseString);
    }

}


