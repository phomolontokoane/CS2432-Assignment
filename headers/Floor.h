#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Shelf.h"
#include "Manager.h"
#include "LinkedList.h"

class Floor
{
private:
    int f_num;
    LinkedList<Shelf> shelves; // Use LinkedList for shelves
    Manager manager;

public:
    Floor(int, Manager &);
    ~Floor();

    int getFloorNum();
    int getNumShelves();
    LinkedList<Shelf> &getShelves(); // Return reference to shelves
    Manager getManager();

    void setFloorNum(int);
    void setManager(Manager &);
    void addShelf(const Shelf &); // Add a shelf to the floor
    void display(); // Display floor details
};

Floor::Floor(int id, Manager &M) : f_num(id), manager(M) {}
Floor::~Floor() {}

int Floor::getFloorNum() { return f_num; }
int Floor::getNumShelves() { return shelves.getSize(); }
LinkedList<Shelf> &Floor::getShelves() { return shelves; }
Manager Floor::getManager() { return manager; }

void Floor::setFloorNum(int id) { f_num = id; }
void Floor::setManager(Manager &M) { manager = M; }
void Floor::addShelf(const Shelf &shelf) { shelves.add(shelf); }

void Floor::display()
{
    std::cout << "Floor Number: " << f_num << "\n";
    manager.display();
    std::cout << "Shelves on Floor:\n";
    for (int i = 0; i < shelves.getSize(); i++) {
        std::cout << "  ";
        shelves[i].display();
        std::cout << "\n";
    }
}

#endif