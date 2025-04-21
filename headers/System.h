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

    // Floor sytstem
    void displayFloors();
    void displayShelves();
    void displayBooks(); // Of A shelf

    void createFloor();
    void createShelf();
    void createBook();

    // Record system
    void displayRecords();
    void displayBorrowedBooks();
    void displayReturnedBooks();

    void handleReturnBook();

    void loadData();
};

///////////////////////////////////////////////////////////////////////////////////

void System::displayFloors()
{
    cout << "Floors: " << "\n";
    
    if (floors.getSize() <= 0) {
        cout << "There are no floors" << "\n\n";
        return;
    }

    for (size_t i = 0; i < floors.getSize(); i++)
    {
        cout << "Floor " << floors[i].getFloorNum() << '\n';
    }
    
}

void System::displayShelves()
{
    int floorNum;
    cout << "Enter the floor number to display shelves: ";
    cin >> floorNum;

    // Find the floor
    Floor* floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++) {
        if (floors[i].getFloorNum() == floorNum) {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr) {
        cout << "Floor not found.\n";
        return;
    }

    cout << "Shelves on Floor " << floorNum << ":\n";
    for (int i = 0; i < floor->getNumShelves(); i++) {
        floor->getShelves()[i].display();
        cout << "-------------------------\n";
    }
}

void System::displayBooks()
{
    int floorNum, shelfId;
    cout << "Enter the floor number: ";
    cin >> floorNum;
    cout << "Enter the shelf ID: ";
    cin >> shelfId;

    // Find the floor
    Floor* floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++) {
        if (floors[i].getFloorNum() == floorNum) {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr) {
        cout << "Floor not found.\n";
        return;
    }

    // Find the shelf
    Shelf* shelf = nullptr;
    for (int i = 0; i < floor->getNumShelves(); i++) {
        if (floor->getShelves()[i].getId() == shelfId) {
            shelf = &floor->getShelves()[i];
            break;
        }
    }

    if (shelf == nullptr) {
        cout << "Shelf not found.\n";
        return;
    }

    cout << "Books on Shelf " << shelfId << ":\n";
    for (int i = 0; i < shelf->getNumBooks(); i++) {
        shelf->getBooks()[i].display();
        cout << "-------------------------\n";
    }
}

void System::createFloor()
{
    string name, surname, id;
    int rank;

    cout << "Manager detials: " << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter rank: ";
    cin >> rank;

    Manager manager(name, surname, id, rank);
    int floorNum;

    cout << "Enter floor number: ";
    cin >> floorNum;

    Floor floor(floorNum, manager);
    floors.add(floor);
}

void System::createShelf()
{
    int floorNum, shelfId;
    cout << "Enter the floor number to add a shelf: ";
    cin >> floorNum;
    cout << "Enter the new shelf ID: ";
    cin >> shelfId;

    // Find the floor
    Floor* floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++) {
        if (floors[i].getFloorNum() == floorNum) {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr) {
        cout << "Floor not found.\n";
        return;
    }

    // Add the new shelf
    Shelf newShelf(shelfId);
    floor->addShelf(newShelf);
    cout << "Shelf " << shelfId << " added to Floor " << floorNum << ".\n";
}

void System::createBook()
{
    int floorNum, shelfId, bookId, copies;
    string title, author, subject;

    cout << "Enter the floor number: ";
    cin >> floorNum;
    cout << "Enter the shelf ID: ";
    cin >> shelfId;

    // Find the floor
    Floor* floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++) {
        if (floors[i].getFloorNum() == floorNum) {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr) {
        cout << "Floor not found.\n";
        return;
    }

    // Find the shelf
    Shelf* shelf = nullptr;
    for (int i = 0; i < floor->getNumShelves(); i++) {
        if (floor->getShelves()[i].getId() == shelfId) {
            shelf = &floor->getShelves()[i];
            break;
        }
    }

    if (shelf == nullptr) {
        cout << "Shelf not found.\n";
        return;
    }

    // Get book details
    cout << "Enter book ID: ";
    cin >> bookId;
    cin.ignore(); // Clear the input buffer
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book subject: ";
    getline(cin, subject);
    cout << "Enter number of copies: ";
    cin >> copies;

    // Add the new book
    Book newBook(bookId, title, author, subject, copies);
    shelf->addBook(newBook);
    cout << "Book \"" << title << "\" added to Shelf " << shelfId << " on Floor " << floorNum << ".\n";
}
///////////////////////////////////////////////////////////////////////////////////

void System::displayRecords()
{
    if (records.getSize() <= 0) {
        cout << "No records available.\n";
        return;
    }

    cout << "All Records:\n";
    for (int i = 0; i < records.getSize(); i++) {
        records[i].display();
        cout << "-------------------------\n";
    }
}

void System::displayBorrowedBooks()
{
    bool found = false;
    cout << "Borrowed Books:\n";
    for (int i = 0; i < records.getSize(); i++) {
        // Assuming the `Record` class has a method `isReturned()` to check if the book is returned
        if (!records[i].isReturned()) {
            records[i].display();
            cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No borrowed books found.\n";
    }
}

void System::displayReturnedBooks()
{
    bool found = false;
    cout << "Returned Books:\n";
    for (int i = 0; i < records.getSize(); i++) {
        // Assuming the `Record` class has a method `isReturned()` to check if the book is returned
        if (records[i].isReturned()) {
            records[i].display();
            cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No returned books found.\n";
    }
}

void System::handleReturnBook()
{
    int recordIndex;
    cout << "Enter the record index of the book to return: ";
    cin >> recordIndex;

    if (recordIndex < 0 || recordIndex >= records.getSize()) {
        cout << "Invalid record index.\n";
        return;
    }

    // Assuming the `Record` class has a method `markAsReturned()` to mark the book as returned
    records[recordIndex].markAsReturned();
    cout << "Book marked as returned.\n";
}

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
    if (!FloorsData || !ManagersData || !ShelvesData || !BooksData || !RecordsData)
    {
        throw std::runtime_error("One or more data files not found");
    }

    // Load Managers
    LinkedList<Manager> managers;
    string record;
    while (getline(ManagersData, record))
    {
        stringstream ss(record);
        string id, rank, name, surname;
        getline(ss, id, '_');
        getline(ss, rank, '_');
        getline(ss, name, '-');
        getline(ss, surname);

        Manager manager(name, surname, id, stoi(rank));
        managers.add(manager);
    }

    // Load Floors
    while (getline(FloorsData, record))
    {
        stringstream ss(record);
        string floorNum, managerId, shelvesData;
        getline(ss, floorNum, '_');
        getline(ss, managerId, '_');
        getline(ss, shelvesData, '_');

        // Find the manager by ID
        Manager *manager = NULL;
        for (int i = 0; i < managers.getSize(); i++)
        {
            if (managers[i].getId() == managerId)
            {
                manager = &managers[i];
                break;
            }
        }

        if (manager == NULL)
        {
            throw std::runtime_error("Manager not found for floor");
        }

        // Create the floor
        Floor floor(stoi(floorNum), *manager);

        // Parse and add shelves to the floor
        stringstream shelvesStream(shelvesData);
        string shelfId;
        while (getline(shelvesStream, shelfId, ','))
        {
            Shelf shelf(stoi(shelfId));
            floor.addShelf(shelf);
        }

        floors.add(floor);
    }

    // Load Shelves
    while (getline(ShelvesData, record))
    {
        stringstream ss(record);
        string shelfId, booksData;
        getline(ss, shelfId, '_');
        getline(ss, booksData, '_');

        // Find the shelf by ID
        Shelf *shelf = NULL;
        for (int i = 0; i < floors.getSize(); i++)
        {
            Floor &floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++)
            {
                if (floor.getShelves()[j].getId() == stoi(shelfId))
                {
                    shelf = &floor.getShelves()[j];
                    break;
                }
            }
        }

        if (shelf == NULL)
        {
            throw std::runtime_error("Shelf not found for books");
        }

        // Parse and add books to the shelf
        stringstream booksStream(booksData);
        string bookId;
        while (getline(booksStream, bookId, ','))
        {
            Book book(stoi(bookId), "", "", "", 0); // Placeholder book
            shelf->addBook(book);
        }
    }

    // Load Books
    while (getline(BooksData, record))
    {
        stringstream ss(record);
        string id, title, author, subject, copies;
        getline(ss, id, '_');
        getline(ss, title, '_');
        getline(ss, author, '_');
        getline(ss, subject, '_');
        getline(ss, copies);

        // Find the book by ID and update its details
        for (int i = 0; i < floors.getSize(); i++)
        {
            Floor &floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++)
            {
                Shelf &shelf = floor.getShelves()[j];
                for (int k = 0; k < shelf.getNumBooks(); k++)
                {
                    if (shelf.getBooks()[k].getId() == stoi(id))
                    {
                        Book &book = shelf.getBooks()[k];
                        book.setTitle(title);
                        book.setAuthor(author);
                        book.setSubject(subject);
                        book.setCopies(stoi(copies));
                        book.display();
                    }
                }
            }
        }
    }

    // Load Records
    while (getline(RecordsData, record))
    {
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
        Book *book = NULL;
        for (int i = 0; i < floors.getSize(); i++)
        {
            Floor &floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++)
            {
                Shelf &shelf = floor.getShelves()[j];
                for (int k = 0; k < shelf.getNumBooks(); k++)
                {
                    if (shelf.getBooks()[k].getId() == stoi(bookId))
                    {
                        book = &shelf.getBooks()[k];
                        break;
                    }
                }
            }
        }

        if (book == NULL)
        {
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

#endif