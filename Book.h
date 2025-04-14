#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string subject;
    int no_copies;

public:
    // Constructor
    Book(string, string, string, int);

    // Getters and Setters

    void setTitle(string);
    void setAuthor(string);
    void setSubject(string);
    void setNum(int);
    
    string getTitle();
    string getAuthor();
    string getSubjuct();
    int getNum();
};

Book::Book(string Title, string Author, string Subject, int Num)
 : title(Title), author(Author), subject(subject), no_copies(Num) {}

void Book::setTitle(string Title) { title = Title; }
void Book::setAuthor(string Author) { author = Author; }
void Book::setSubject(string Subject) { subject = Subject; }
void Book::setNum(int Num) { no_copies = Num;}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getSubjuct() { return subject; }
int Book::getNum() { return no_copies; }


#endif