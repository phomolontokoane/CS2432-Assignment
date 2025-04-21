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
    Book(const Book &);

    // Getters and Setters

    void setId(int);
    void setTitle(string);
    void setAuthor(string);
    void setSubject(string);
    void setCopies(int);

    string getTitle();
    string getAuthor();
    string getSubjuct();
    int getCopies();
    int getId();

    // Assignment operator overload
    Book &operator=(Book &B);

    // Display function
    void display();
};

// Constructor implementation
Book::Book(int Id, string Title, string Author, string Subject, int Num)
    : id(Id), title(Title), author(Author), subject(Subject), no_copies(Num) {}

Book::Book(const Book &B)
    : id(B.id), title(B.title), author(B.author), subject(B.subject), no_copies(B.no_copies) {}

// Getters and Setters implementation

void Book::setId(int Id) { id = Id; }
void Book::setTitle(string Title) { title = Title; }
void Book::setAuthor(string Author) { author = Author; }
void Book::setSubject(string Subject) { subject = Subject; }
void Book::setCopies(int Num) { no_copies = Num; }

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getSubjuct() { return subject; }
int Book::getCopies() { return no_copies; }

int Book::getId() { return id; }

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

// Display function implementation
void Book::display()
{
    std::cout << "Book ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Subject: " << subject << "\n";
    std::cout << "Number of Copies: " << no_copies << "\n";
}

#endif