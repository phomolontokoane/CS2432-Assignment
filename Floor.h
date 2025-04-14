#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Shelf.h"
#include "Manager.h"

class Floor
{
private:
    int f_num;
    Shelf* shelves;
    int num_shelves;
    Manager manager;

public:
    Floor(int, Manager&);
    ~Floor();

    int getFloorNum();
    int getNumShelves();
    Shelf* getShelves();
    Manager getManager();

    void setFloorNum(int);
    void setNumShelves(int);
    void setShelves(Shelf*);
    void setManager(Manager&);
};

Floor::Floor(int id, Manager& M)
 : f_num(id), manager(M), shelves(nullptr), num_shelves(0) {}


Floor::~Floor() { delete[] shelves; }

int Floor::getFloorNum() { return f_num; }
int Floor::getNumShelves() { return num_shelves; }
Shelf* Floor::getShelves() { return shelves; }
Manager Floor::getManager() { return manager; }

void Floor::setFloorNum(int id) { f_num = id; }
void Floor::setNumShelves(int num) { num_shelves = num; }
void Floor::setShelves(Shelf* Shelves) { shelves = Shelves; }
void Floor::setManager(Manager& M) { manager = M; }

#endif