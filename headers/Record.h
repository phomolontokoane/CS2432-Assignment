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
public:
    Record(Student&, Date&, Book&, int, int);
};

Record::Record(Student &S,Date &D, Book &B, int FNum, int SNum):
student(S), date(D), book(B), floorNum(FNum), shelfNum(SNum)
{}

#endif
