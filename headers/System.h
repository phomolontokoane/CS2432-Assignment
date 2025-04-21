#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    // Open data files
    ifstream FloorsData("data/floors.txt");
    ifstream ManagersData("data/managers.txt");
    ifstream ShelvesData("data/shelves.txt");
    ifstream BooksData("data/books.txt");
    ifstream RecordsData("data/records.txt");

    // Check if all necessary data files were loaded
    if (!FloorsData || !ManagersData || !ShelvesData || !BooksData || !RecordsData) {
        throw std::runtime_error("One or more data files not found");
    }

    // Load Managers
    LinkedList<Manager> managers;
    string record;
    while (getline(ManagersData, record)) {
        stringstream ss(record);
        string id, rank, name, surname;
        getline(ss, id, '_');
        getline(ss, rank, '_');
        getline(ss, name, '-');
        getline(ss, surname);

        Manager manager(name, surname, stoi(id), stoi(rank));
        managers.add(manager);
    }

    // Load Floors
    while (getline(FloorsData, record)) {
        stringstream ss(record);
        string floorNum, managerId;
        getline(ss, floorNum, '_');
        getline(ss, managerId, '_');

        // Find the manager by ID
        Manager* manager = nullptr;
        for (int i = 0; i < managers.getSize(); i++) {
            if (managers[i].getId() == stoi(managerId)) {
                manager = &managers[i];
                break;
            }
        }

        if (manager == nullptr) {
            throw std::runtime_error("Manager not found for floor");
        }

        Floor floor(stoi(floorNum), *manager);
        floors.add(floor);
    }

    // Load Shelves
    while (getline(ShelvesData, record)) {
    stringstream ss(record);
    string floorNum, shelfId;
    getline(ss, floorNum, '_');
    getline(ss, shelfId, '+');

    // Find the floor by number
    Floor *floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++) {
        if (floors[i].getFloorNum() == stoi(floorNum)) {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr) {
        throw std::runtime_error("Floor not found for shelf");
    }

    Shelf shelf(stoi(shelfId));
    floor->addShelf(shelf); // Add shelf to the floor
}
    // Load Books
    while (getline(BooksData, record)) {
        stringstream ss(record);
        string id, title, author, subject, copies;
        getline(ss, id, '_');
        getline(ss, title, '_');
        getline(ss, author, '_');
        getline(ss, subject, '_');
        getline(ss, copies);

        Book book(stoi(id), title, author, subject, stoi(copies));

        // Assign the book to a shelf
        for (int i = 0; i < floors.getSize(); i++) {
            Floor &floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++) {
                Shelf &shelf = floor.getShelves()[j];
                if (shelf.getId() == stoi(id)) {
                    shelf.addBook(book); // Add book to the shelf
                    break;
                }
            }
        }
    }

    // Load Records
    while (getline(RecordsData, record)) {
        stringstream ss(record);
        string name, surname, stdNo, faculty, date, floorNum, shelfNum, bookId;
        getline(ss, name, '+');
        getline(ss, surname, '+');
        getline(ss, stdNo, '+');
        getline(ss, faculty, '_');
        getline(ss, date, '_');
        getline(ss, floorNum, '_');
        getline(ss, shelfNum, '_');
        getline(ss, bookId);

        // Parse date
        stringstream dateStream(date);
        string year, month, day;
        getline(dateStream, year, '-');
        getline(dateStream, month, '-');
        getline(dateStream, day);

        Date recordDate(stoi(year), stoi(month), stoi(day));
        Student student(name, surname, stoi(stdNo), faculty);

        // Find the book
        Book* book = nullptr;
        for (int i = 0; i < floors.getSize(); i++) {
            Floor& floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++) {
                Shelf& shelf = floor.getShelves()[j];
                for (int k = 0; k < shelf.getNumBooks(); k++) {
                    if (shelf.getBooks()[k].getTitle() == bookId) {
                        book = &shelf.getBooks()[k];
                        break;
                    }
                }
            }
        }

        if (book == nullptr) {
            throw std::runtime_error("Book not found for record");
        }

        Record record(student, recordDate, *book, stoi(floorNum), stoi(shelfNum));
        records.add(record);
    }

    // Close files
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