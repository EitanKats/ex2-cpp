//
// Created by Eitan Kats on 21/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"

using namespace ariel;

Notebook notebook;

TEST_CASE ("Bad input - writing empty line saved character") {
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "_"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "_"));
}

TEST_CASE ("Bad input - pass line boundaries") {
            CHECK_THROWS(notebook.write(0, 1, 95, Direction::Horizontal, "1234567"));
            CHECK_THROWS(notebook.read(0, 1, 95, Direction::Horizontal, 7));
            CHECK_THROWS(notebook.erase(0, 1, 95, Direction::Horizontal, 7));
}

TEST_CASE ("Bad input - end of string character") {
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "\0"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "\0"));
}

TEST_CASE ("Attempt to double write on the same spot") {
    notebook.write(0, 1, 1, Direction::Horizontal, "a");
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "1"));
}

TEST_CASE ("Attempt to write on deleted text") {
    notebook.write(0, 1, 1, Direction::Horizontal, "a");
    notebook.erase(0, 1, 1, Direction::Horizontal, 1);
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "a"));
}