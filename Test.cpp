//
// Created by Eitan Kats on 21/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"

using namespace ariel;

Notebook notebook;

TEST_CASE ("Bad input - writing empty line saved character") {

    CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "_"));
}