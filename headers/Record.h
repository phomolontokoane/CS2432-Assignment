#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include "Student.h"
#include "Book.h"
#include "Date.h"

class Record
{
private:
    Student student;
    Date date;
    Book book;
    int floorNum, shelfNum;
    bool returned; // Indicates whether the book has been returned

public:
    // Constructor
    Record(Student&, Date&, Book&, int, int);

    // Getters
    Student& getStudent();
    Date& getDate();
    Book& getBook();
    int getFloorNum();
    int getShelfNum();
    bool isReturned();

    // Setters
    void setStudent(Student&);
    void setDate(Date&);
    void setBook(Book&);
    void setFloorNum(int);
    void setShelfNum(int);
    void markAsReturned();

    // Display function
    void display();
};

// Constructor implementation
Record::Record(Student &S, Date &D, Book &B, int FNum, int SNum)
    : student(S), date(D), book(B), floorNum(FNum), shelfNum(SNum), returned(false) {}

// Getters
Student& Record::getStudent() { return student; }
Date& Record::getDate() { return date; }
Book& Record::getBook() { return book; }
int Record::getFloorNum() { return floorNum; }
int Record::getShelfNum() { return shelfNum; }
bool Record::isReturned() { return returned; }

// Setters
void Record::setStudent(Student &S) { student = S; }
void Record::setDate(Date &D) { date = D; }
void Record::setBook(Book &B) { book = B; }
void Record::setFloorNum(int FNum) { floorNum = FNum; }
void Record::setShelfNum(int SNum) { shelfNum = SNum; }
void Record::markAsReturned() { returned = true; }

// Display function
void Record::display()
{
    std::cout << "Record Details:\n";
    std::cout << "Student:\n";
    student.display();
    std::cout << "Date: ";
    date.display();
    std::cout << "Book:\n";
    book.display();
    std::cout << "Floor Number: " << floorNum << "\n";
    std::cout << "Shelf Number: " << shelfNum << "\n";
    std::cout << "Status: " << (returned ? "Returned" : "Borrowed") << "\n";
}

#endif
