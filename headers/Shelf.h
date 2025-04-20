#ifndef SHELF_H
#define SHELF_H
#include <iostream>
#include "Book.h"

class Shelf
{
private:
    int id;
    Book *books;
    int numBooks;

public:
    Shelf(int);
    ~Shelf();

    void setId(int);
    void setBooks(Book *);
    void setNumBooks(int);

    int getId();
    Book *getBooks();
    int getNumBookks();
};

Shelf::Shelf(int Id) : books(nullptr), numBooks(0), id(Id) {}
Shelf::~Shelf()
{
    delete[] books;
    books = nullptr;
}

void Shelf::setId(int Id) { id = Id; }
void Shelf::setBooks(Book *Books) { books = Books; }
void Shelf::setNumBooks(int Num) { numBooks = Num; }

int Shelf::getId() { return id; }
Book *Shelf::getBooks() { return books; }
int Shelf::getNumBookks() { return numBooks; }

#endif