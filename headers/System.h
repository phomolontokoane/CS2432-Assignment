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

    // Helper functions for loading data
    void loadManagers(LinkedList<Manager> &managers);
    void loadFloors(LinkedList<Manager> &managers);
    void loadShelves();
    void loadBooks();
    void loadRecords();

public:
    // Methods

    // Floor system
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

    void loadData(); // Main function to load all data
    void saveData(); // Main function to save all data
};

///////////////////////////////////////////////////////////////////////////////////

void System::displayFloors()
{
    cout << "Floors: " << "\n";

    if (floors.getSize() <= 0)
    {
        cout << "There are no floors" << "\n";
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
    Floor *floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++)
    {
        if (floors[i].getFloorNum() == floorNum)
        {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr)
    {
        cout << "Floor not found.\n";
        return;
    }

    cout << "Shelves on Floor " << floorNum << ":\n";
    for (int i = 0; i < floor->getNumShelves(); i++)
    {
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
    Floor *floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++)
    {
        if (floors[i].getFloorNum() == floorNum)
        {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr)
    {
        cout << "Floor not found.\n";
        return;
    }

    // Find the shelf
    Shelf *shelf = nullptr;
    for (int i = 0; i < floor->getNumShelves(); i++)
    {
        if (floor->getShelves()[i].getId() == shelfId)
        {
            shelf = &floor->getShelves()[i];
            break;
        }
    }

    if (shelf == nullptr)
    {
        cout << "Shelf not found.\n";
        return;
    }

    cout << "Books on Shelf " << shelfId << ":\n";
    for (int i = 0; i < shelf->getNumBooks(); i++)
    {
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
    Floor *floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++)
    {
        if (floors[i].getFloorNum() == floorNum)
        {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr)
    {
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
    Floor *floor = nullptr;
    for (int i = 0; i < floors.getSize(); i++)
    {
        if (floors[i].getFloorNum() == floorNum)
        {
            floor = &floors[i];
            break;
        }
    }

    if (floor == nullptr)
    {
        cout << "Floor not found.\n";
        return;
    }

    // Find the shelf
    Shelf *shelf = nullptr;
    for (int i = 0; i < floor->getNumShelves(); i++)
    {
        if (floor->getShelves()[i].getId() == shelfId)
        {
            shelf = &floor->getShelves()[i];
            break;
        }
    }

    if (shelf == nullptr)
    {
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
    if (records.getSize() <= 0)
    {
        cout << "No records available.\n";
        return;
    }

    cout << "All Records:\n";
    for (int i = 0; i < records.getSize(); i++)
    {
        records[i].display();
        cout << "-------------------------\n";
    }
}

void System::displayBorrowedBooks()
{
    bool found = false;
    cout << "Borrowed Books:\n";
    for (int i = 0; i < records.getSize(); i++)
    {
        // Assuming the `Record` class has a method `isReturned()` to check if the book is returned
        if (!records[i].isReturned())
        {
            records[i].display();
            cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No borrowed books found.\n";
    }
}

void System::displayReturnedBooks()
{
    bool found = false;
    cout << "Returned Books:\n";
    for (int i = 0; i < records.getSize(); i++)
    {
        // Assuming the `Record` class has a method `isReturned()` to check if the book is returned
        if (records[i].isReturned())
        {
            records[i].display();
            cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No returned books found.\n";
    }
}

void System::handleReturnBook()
{
    int recordIndex;
    cout << "Enter the record index of the book to return: ";
    cin >> recordIndex;

    if (recordIndex < 0 || recordIndex >= records.getSize())
    {
        cout << "Invalid record index.\n";
        return;
    }

    // Assuming the `Record` class has a method `markAsReturned()` to mark the book as returned
    records[recordIndex].markAsReturned();
    cout << "Book marked as returned.\n";
}

///////////////////////////////////////////////////////////////////////////////////

void System::loadManagers(LinkedList<Manager> &managers)
{
    ifstream ManagersData("data/managers.txt");
    if (!ManagersData)
    {
        throw runtime_error("Managers data file not found");
    }

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

    ManagersData.close();
}

void System::loadFloors(LinkedList<Manager> &managers)
{
    ifstream FloorsData("data/floors.txt");
    if (!FloorsData)
    {
        throw runtime_error("Floors data file not found");
    }

    string record;
    while (getline(FloorsData, record))
    {
        stringstream ss(record);
        string floorNum, managerId, shelvesData;
        getline(ss, floorNum, '_');
        getline(ss, managerId, '_');
        getline(ss, shelvesData, '_');

        // Find the manager by ID
        Manager *manager = nullptr;
        for (int i = 0; i < managers.getSize(); i++)
        {
            if (managers[i].getId() == managerId)
            {
                manager = &managers[i];
                break;
            }
        }

        if (manager == nullptr)
        {
            throw runtime_error("Manager not found for floor");
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
        cout << "Good" << '\n';
    }

    FloorsData.close();
}

void System::loadShelves()
{
    ifstream ShelvesData("data/shelves.txt");
    if (!ShelvesData)
    {
        throw runtime_error("Shelves data file not found");
    }

    string record;
    while (getline(ShelvesData, record))
    {
        stringstream ss(record);
        string shelfId, booksData;
        getline(ss, shelfId, '_');
        getline(ss, booksData, '_');

        // Find the shelf by ID
        Shelf *shelf = nullptr;
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

        if (shelf == nullptr)
        {
            throw runtime_error("Shelf not found for books");
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

    ShelvesData.close();
}

void System::loadBooks()
{
    ifstream BooksData("data/books.txt");
    if (!BooksData)
    {
        throw runtime_error("Books data file not found");
    }

    string record;
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
                    }
                }
            }
        }
    }

    BooksData.close();
}

void System::loadRecords()
{
    ifstream RecordsData("data/records.txt");
    if (!RecordsData)
    {
        throw runtime_error("Records data file not found");
    }

    string record;
    while (getline(RecordsData, record))
    {
        stringstream ss(record);
        string name, surname, stdNo, faculty, date, floorNum, shelfNum, bookId, bookTitle, bookAuthor, bookSubject, bookCopies, isReturned;
        
        
        // Parse student details
        getline(ss, name, '+');
        getline(ss, surname, '+');
        getline(ss, stdNo, '+');
        getline(ss, faculty, '_');
        
        // Parse date
        getline(ss, date, '_');
        stringstream dateStream(date);
        string year, month, day;
        getline(dateStream, year, '-');
        getline(dateStream, month, '-');
        getline(dateStream, day);
        
        // Parse floor and shelf numbers
        getline(ss, floorNum, '_');
        getline(ss, shelfNum, '_');
        
        // Parse book details
        getline(ss, bookId, '_');
        getline(ss, bookTitle, '_');
        getline(ss, bookAuthor, '_');
        getline(ss, bookSubject, '_');
        getline(ss, bookCopies, '_');
        
        // Parse return status
        getline(ss, isReturned);

        cout << bookId << '\n';
        cout << bookTitle << '\n';
        cout << bookAuthor << '\n';
        cout << bookSubject << '\n';
        cout << bookCopies << '\n';
        
        // Create objects
        Date recordDate(stoi(year), stoi(month), stoi(day));
        Student student(name, surname, stoi(stdNo), faculty);
        Book book(stoi(bookId), bookTitle, bookAuthor, bookSubject, stoi(bookCopies));
        
        // Find the book in the system
        Book *systemBook = nullptr;
        for (int i = 0; i < floors.getSize(); i++)
        {
            Floor &floor = floors[i];
            for (int j = 0; j < floor.getNumShelves(); j++)
            {
                Shelf &shelf = floor.getShelves()[j];
                for (int k = 0; k < shelf.getNumBooks(); k++)
                {
                    if (shelf.getBooks()[k].getId() == book.getId())
                    {
                        systemBook = &shelf.getBooks()[k];
                        break;
                    }
                }
            }
        }

        if (systemBook == nullptr)
        {
            // throw runtime_error("Book not found for record");
        }

        // Create the record
        Record recordObj(student, recordDate, book, stoi(floorNum), stoi(shelfNum));
        if (isReturned == "True")
        {
            recordObj.markAsReturned();
        }

        records.add(recordObj);
    }

    RecordsData.close();
}

void System::loadData()
{
    LinkedList<Manager> managers;

    // Load data in sequence
    // loadManagers(managers);
    // loadFloors(managers);
    // loadShelves();
    // loadBooks();
    loadRecords();
}

void System::saveData()
{
    // Save Managers
    ofstream ManagersData("data/managers.txt");
    if (!ManagersData)
    {
        throw runtime_error("Failed to open managers data file for writing");
    }

    for (int i = 0; i < floors.getSize(); i++)
    {
        Manager manager = floors[i].getManager();
        ManagersData << manager.getId() << "_" << manager.getRank() << "_" << manager.getName() << "-" << manager.getSurname() << "\n";
    }
    ManagersData.close();

    // Save Floors
    ofstream FloorsData("data/floors.txt");
    if (!FloorsData)
    {
        throw runtime_error("Failed to open floors data file for writing");
    }

    for (int i = 0; i < floors.getSize(); i++)
    {
        Floor &floor = floors[i];
        FloorsData << floor.getFloorNum() << "_" << floor.getManager().getId() << "_";

        for (int j = 0; j < floor.getNumShelves(); j++)
        {
            FloorsData << floor.getShelves()[j].getId();
            if (j < floor.getNumShelves() - 1)
                FloorsData << ",";
        }
        FloorsData << "\n";
    }
    FloorsData.close();

    // Save Shelves
    ofstream ShelvesData("data/shelves.txt");
    if (!ShelvesData)
    {
        throw runtime_error("Failed to open shelves data file for writing");
    }

    for (int i = 0; i < floors.getSize(); i++)
    {
        Floor &floor = floors[i];
        for (int j = 0; j < floor.getNumShelves(); j++)
        {
            Shelf &shelf = floor.getShelves()[j];
            ShelvesData << shelf.getId() << "_";

            for (int k = 0; k < shelf.getNumBooks(); k++)
            {
                ShelvesData << shelf.getBooks()[k].getId();
                if (k < shelf.getNumBooks() - 1)
                    ShelvesData << ",";
            }
            ShelvesData << "\n";
        }
    }
    ShelvesData.close();

    // Save Books
    ofstream BooksData("data/books.txt");
    if (!BooksData)
    {
        throw runtime_error("Failed to open books data file for writing");
    }

    for (int i = 0; i < floors.getSize(); i++)
    {
        Floor &floor = floors[i];
        for (int j = 0; j < floor.getNumShelves(); j++)
        {
            Shelf &shelf = floor.getShelves()[j];
            for (int k = 0; k < shelf.getNumBooks(); k++)
            {
                Book &book = shelf.getBooks()[k];
                BooksData << book.getId() << "_" << book.getTitle() << "_" << book.getAuthor() << "_" << book.getSubjuct() << "_" << book.getCopies() << "\n";
            }
        }
    }
    BooksData.close();

    // Save Records
    ofstream RecordsData("data/records.txt");
    if (!RecordsData)
    {
        throw runtime_error("Failed to open records data file for writing");
    }

    for (int i = 0; i < records.getSize(); i++)
    {
        Record &record = records[i];
        RecordsData << record.getStudent().getName() << "+" << record.getStudent().getSurname() << "+" << record.getStudent().getStdNo() << "+" << record.getStudent().getFaculty() << "_";
        RecordsData << record.getDate().getYear() << "-" << record.getDate().getMonth() << "-" << record.getDate().getDay() << "_";
        RecordsData << record.getFloorNum() << "_" << record.getShelfNum() << "_" << record.getBook().getId() << "\n";
    }
    RecordsData.close();
}

#endif