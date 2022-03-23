#include "doctest.h"
#include "Notebook.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Good input")
{
	Notebook notebook;
    //check the starting position
	CHECK((notebook.read(0, 0, 0, Direction::Horizontal, 6)) == ("______"));
	CHECK((notebook.read(0, 0, 0, Direction::Vertical, 3)) == ("___"));

    //write and read checking in diffrent locations and directions
    notebook.write(5, 16, 0, Direction::Horizontal, "first check1");
	CHECK((notebook.read(5, 16, 0, Direction::Horizontal, 12)) == ("first check1"));

	notebook.write(50, 26, 0, Direction::Vertical, "now vertical2");
	CHECK((notebook.read(50, 26, 0, Direction::Vertical, 13)) == ("now vertical2"));

    //read a part of the written 
	CHECK((notebook.read(5, 16, 0, Direction::Horizontal, 8)) == ("first ch"));
	CHECK((notebook.read(50, 26, 0, Direction::Vertical, 9)) == ("now verti"));
	
    //erase whole sentece and try to read it
	notebook.erase(5, 16, 0, Direction::Horizontal, 12);
	CHECK(notebook.read(5, 16, 0, Direction::Horizontal, 12) == ("~~~~~~~~~~~~"));
	
    notebook.erase(50, 26, 0, Direction::Vertical, 3);
	CHECK(notebook.read(50, 26, 0, Direction::Vertical, 13) == ("~~~ vertical2"));
	
    //read vertical in horozontial
    CHECK(notebook.read(50, 32, 0, Direction::Horizontal, 5) == ("r____"));
	CHECK(notebook.read(50, 33, 0, Direction::Vertical, 3) == ("t__"));
}

TEST_CASE("negative input")
{
	Notebook notebook;
	CHECK_THROWS(notebook.write(-1, 0, 7, Direction::Vertical, "doesn't matter"));
    CHECK_THROWS(notebook.read(3, 10, 27, Direction:: Horizontal, -9));
    CHECK_THROWS(notebook.erase(11, 10, -7, Direction::Vertical, -8));
	CHECK_THROWS(notebook.show(-9));
}

TEST_CASE("too large input"){
    Notebook notebook;
    //cant write more than 100 chars in a row
    CHECK_THROWS(notebook.write(1, 0, 0, Direction:: Horizontal, "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 "));
    CHECK_THROWS(notebook.write(0, 99, 99, Direction::Horizontal, "123"));
    CHECK_THROWS(notebook.erase(12, 1, 1, Direction:: Horizontal, 101));
    CHECK_THROWS(notebook.read(11, 12, 13, Direction::Horizontal, 101));
}

TEST_CASE("write on erased or write illegal char"){
    Notebook notebook;
    notebook.erase(0, 0, 0, Direction::Horizontal, 10);
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, "illegal"));
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "still illegal"));
    CHECK_THROWS(notebook.write(1, 0, 0, Direction::Vertical, "~~~"));
}