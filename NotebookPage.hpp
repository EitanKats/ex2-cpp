//
// Created by Eitan Kats on 21/03/2022.
//
#include "map"
#include "vector"
#include "string"

#ifndef EX2_CPP_NOTEBOOKPAGE_HPP
#define EX2_CPP_NOTEBOOKPAGE_HPP

using std::map;
using std::vector;
using std::string;
namespace ariel {
    class Page {
    private:
        map<int, vector<char>> linesMap;
    public:
        string getPrettyString();
    };

}

#endif //EX2_CPP_NOTEBOOKPAGE_HPP
