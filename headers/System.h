#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>

#include "LinkedList.h"
#include "Floor.h"
#include "Record.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////

class System
{
    private:
        LinkedList<Floor> floors;
        LinkedList<Record> records;
    public:
        // Methods
        void loadData();
        
        void displayFloors();
        void displayShelves();
        void displayBooks(); // Of A shelf

        void createFloor();
        void createShelf();
        void createBook();
        
};

///////////////////////////////////////////////////////////////////////////////////

void System::loadData()
{
    // loading data
    ifstream FloorsData("data/floors.txt");
    ifstream ManagersData("data/managers.txt");
    ifstream ShelvesData("data/shelves.txt");
    ifstream BooksData("data/books.txt");
    ifstream RecordsData("data/records.txt");
    
    // Checking if all necesary data was loaded
    if (!FloorsData || !ManagersData || !ShelvesData || !BooksData, !RecordsData) {
        throw std::runtime_error("data not found");
    }

    // Loading Floors


    // Closing files
    FloorsData.close();
    ManagersData.close();
    ShelvesData.close();
    BooksData.close();
    RecordsData.close();
}

void System::displayFloors()
{

}

void System::createFloor()
{
}

#endif