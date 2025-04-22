#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Shelf.h"
#include "Manager.h"
#include "LinkedList.h"
#include "System.h"

class Floor
{
private:
    int f_num;
    LinkedList<Shelf> shelves; // Use LinkedList for shelves
    Manager manager;

public:
    Floor(int, Manager &);
    Floor(const Floor &); // Copy constructor
    ~Floor();

    int getFloorNum();
    int getNumShelves();
    LinkedList<Shelf> &getShelves(); // Return reference to shelves
    Manager getManager();

    void setFloorNum(int);
    void setManager(Manager &);
    void addShelf(const Shelf &); // Add a shelf to the floor
    void display(); // Display floor details

    friend class System;
};

// Constructor
Floor::Floor(int id, Manager &M) : f_num(id), manager(M) {}

// Copy Constructor
Floor::Floor(const Floor &other) : f_num(other.f_num), manager(other.manager), shelves(other.shelves) {}

// Destructor
Floor::~Floor() {}

// Getters
int Floor::getFloorNum() { return f_num; }
int Floor::getNumShelves() { return shelves.getSize(); }
LinkedList<Shelf> &Floor::getShelves() { return shelves; }
Manager Floor::getManager() { return manager; }

// Setters
void Floor::setFloorNum(int id) { f_num = id; }
void Floor::setManager(Manager &M) { manager = M; }

// Add a shelf
void Floor::addShelf(const Shelf &shelf) { shelves.add(shelf); }

// Display floor details
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