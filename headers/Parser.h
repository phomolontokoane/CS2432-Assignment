#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Floor.h"
#include "Shelf.h"
#include "Book.h"
#include "Record.h"
#include "Manager.h"
#include "Student.h"
#include "Date.h"

using namespace std;

class Parser
{
public:
    // Parse a Manager from a string
    static Manager parseManager(const string &line)
    {
        stringstream ss(line);
        string id, rank, name, surname;
        getline(ss, id, '_');
        getline(ss, rank, '_');
        getline(ss, name, '-');
        getline(ss, surname);

        return Manager(name, surname, id, stoi(rank));
    }

    // Parse a Floor from a string
    static Floor parseFloor(const string &line, LinkedList<Manager> &managers)
    {
        stringstream ss(line);
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

        return floor;
    }

    // Parse a Shelf from a string
    static Shelf parseShelf(const string &line)
    {
        stringstream ss(line);
        string shelfId, booksData;
        getline(ss, shelfId, '_');
        getline(ss, booksData, '_');

        Shelf shelf(stoi(shelfId));

        // Parse and add books to the shelf
        stringstream booksStream(booksData);
        string bookId;
        while (getline(booksStream, bookId, ','))
        {
            Book book(stoi(bookId), "", "", "", 0); // Placeholder book
            shelf.addBook(book);
        }

        return shelf;
    }

    // Parse a Book from a string
    static Book parseBook(const string &line)
    {
        stringstream ss(line);
        string id, title, author, subject, copies;
        getline(ss, id, '_');
        getline(ss, title, '_');
        getline(ss, author, '_');
        getline(ss, subject, '_');
        getline(ss, copies);

        return Book(stoi(id), title, author, subject, stoi(copies));
    }

    // Parse a Record from a string
    static Record parseRecord(const string &line, LinkedList<Floor> &floors)
    {
        stringstream ss(line);
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
        Book *book = nullptr;
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

        if (book == nullptr)
        {
            throw runtime_error("Book not found for record");
        }

        return Record(student, recordDate, *book, stoi(floorNum), stoi(shelfNum));
    }
};

#endif