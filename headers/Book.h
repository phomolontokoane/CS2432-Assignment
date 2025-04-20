#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using std::string;

class Book
{
private:
    int id;
    string title;
    string author;
    string subject;
    int no_copies;

public:
    // Constructor
    Book(int, string, string, string, int);
    Book(Book &);

    // Getters and Setters

    void setId(int);
    void setTitle(string);
    void setAuthor(string);
    void setSubject(string);
    void setNum(int);

    string getTitle();
    string getAuthor();
    string getSubjuct();
    int getNum();

    // Assignment operator overload
    Book &operator=(Book &B);
};

// Constructor implementation
Book::Book(int Id, string Title, string Author, string Subject, int Num)
    : id(Id), title(Title), author(Author), subject(subject), no_copies(Num) {}

Book::Book(Book &B)
    : id(B.id), title(B.title), author(B.author), subject(B.subject), no_copies(B.no_copies) {}

// Getters and Setters implementation

void Book::setId(int Id) { id = Id; }
void Book::setTitle(string Title) { title = Title; }
void Book::setAuthor(string Author) { author = Author; }
void Book::setSubject(string Subject) { subject = Subject; }
void Book::setNum(int Num) { no_copies = Num; }

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getSubjuct() { return subject; }
int Book::getNum() { return no_copies; }

// Assignment operator overload
Book& Book::operator=(Book &B)
{
    if (this != &B) {
        id = B.id;
        title = B.title;
        author = B.author;
        subject = B.subject;
        no_copies = B.no_copies;
    }
    return *this;
}

#endif