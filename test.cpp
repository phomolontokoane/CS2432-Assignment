#include "headers/Parser.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Example data strings
    string managerData = "M1234_5_John-Doe";
    string floorData = "1_M1234_0,1,2";
    string shelfData = "0_1,2,3";
    string bookData = "1_C++ Programming_Bjarne Stroustrup_Programming_5";
    string recordData = "Alice+Smith+12345+Computer Science_2025-04-21_1_0_1";

    // Parse Manager
    Manager manager = Parser::parseManager(managerData);
    manager.display();

    // Create a LinkedList of Managers
    LinkedList<Manager> managers;
    managers.add(manager);

    // Parse Floor
    Floor floor = Parser::parseFloor(floorData, managers);
    floor.display();

    // Parse Shelf
    Shelf shelf = Parser::parseShelf(shelfData);
    shelf.display();

    // Parse Book
    Book book = Parser::parseBook(bookData);
    book.display();

    // Create a LinkedList of Floors
    LinkedList<Floor> floors;
    floors.add(floor);

    // Parse Record
    Record record = Parser::parseRecord(recordData, floors);
    record.display();

    return 0;
}
