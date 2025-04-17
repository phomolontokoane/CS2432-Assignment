#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include "Student.h"
#include "Book.h"

class Date {
    private:
        int year, month, day;
    public:
        Date(int,int,int);
        Date(Date&);
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(Date &D): year(D.year), month(D.month), day(D.day) { }

class Record
{
private:
    Student student;
    Date date;
    Book book;
    int floorNum, shelfNum;
public:
    Record(Student&, Date&, Book&, int, int);
};

Record::Record(Student &S,Date &D, Book &B, int FNum, int SNum):
student(S), date(D), book(B), floorNum(FNum), shelfNum(SNum)
{}

#endif
