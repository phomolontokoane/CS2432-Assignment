#ifndef SHELF_H
#define SHELF_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Book.h"
#include "LinkedList.h"

class Shelf
{
private:
    int id;
    LinkedList<Book> books; // Use LinkedList for books

public:
    Shelf(int);
    ~Shelf();

    void setId(int);
    void addBook(const Book &); // Add a book to the shelf

    int getId();
    LinkedList<Book> &getBooks(); // Return reference to books
    int getNumBooks();            // Get the number of books
};

Shelf::Shelf(int Id) : id(Id) {}
Shelf::~Shelf() {}

void Shelf::setId(int Id) { id = Id; }
void Shelf::addBook(const Book &book) { books.add(book); }

int Shelf::getId() { return id; }
LinkedList<Book> &Shelf::getBooks() { return books; }
int Shelf::getNumBooks() { return books.getSize(); }

#endif