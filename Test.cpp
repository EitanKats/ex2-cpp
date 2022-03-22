//
// Created by Eitan Kats on 21/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include "string"

using std::string;
using namespace ariel;

Notebook notebook;
const int NON_PRINTABLE_LOWER_BOUND = 32;
const int ASCII_END = 255;

TEST_CASE ("Bad input - writing empty line saved character") {
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "_"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "_"));
}

TEST_CASE ("Bad input - pass line boundaries") {
            CHECK_THROWS(notebook.write(0, 1, 95, Direction::Horizontal, "1234567"));
            CHECK_THROWS(notebook.read(0, 1, 95, Direction::Horizontal, 7));
            CHECK_THROWS(notebook.erase(0, 1, 95, Direction::Horizontal, 7));
}

TEST_CASE ("Bad input - negative page, row or column supplied for writing") {
            CHECK_THROWS(notebook.write(-1, 1, 1, Direction::Horizontal, "a"));
            CHECK_THROWS(notebook.write(0, -1, 1, Direction::Vertical, "b"));
            CHECK_THROWS(notebook.write(0, 1, -1, Direction::Vertical, "c"));
}

TEST_CASE ("Bad input - negative page, row or column supplied for reading") {
            CHECK_THROWS(notebook.read(-1, 1, 1, Direction::Horizontal, 1));
            CHECK_THROWS(notebook.read(0, -1, 1, Direction::Vertical, 1));
            CHECK_THROWS(notebook.read(0, 1, -1, Direction::Vertical, 1));
}

TEST_CASE ("Bad input - negative page for showing") {
    CHECK_THROWS(notebook.show(-1));
}

TEST_CASE ("Bad input - end of string character") {
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "\0"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "\0"));
}

TEST_CASE ("Bad input - end of line characters") {
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "\n"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "\n"));

            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Horizontal, "\r"));
            CHECK_THROWS(notebook.write(0, 1, 1, Direction::Vertical, "\r"));
}

TEST_CASE ("Bad input - Non printable characters in text") {
    string testText = "abc";
    //ascii 32 is space so it is valid
    for (int i = 0; i < NON_PRINTABLE_LOWER_BOUND; ++i) {
        char invalidChar = (char) i;
                CHECK_THROWS(notebook.write(3, 0, 0, Direction::Horizontal, testText + invalidChar));
    }

    for (int i = 127; i < ASCII_END; ++i) {
        char invalidChar = (char) i;
                CHECK_THROWS(notebook.write(3, 0, 0, Direction::Horizontal, testText + invalidChar));
    }
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

TEST_CASE ("write and read tests") {
    string firstText = "Hello world";
    string textFromNotebook;
    notebook.write(1, 0, 0, Direction::Horizontal, "Hello world");
    textFromNotebook = notebook.read(1, 0, 0, Direction::Horizontal, 11);

            CHECK(firstText == textFromNotebook);

    notebook.write(1, 1, 0, Direction::Vertical, "Hello world");

    textFromNotebook = notebook.read(1, 1, 0, Direction::Vertical, 11);

            CHECK(firstText == textFromNotebook);
}
