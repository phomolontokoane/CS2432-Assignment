#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    string surname;
public:
    Person(string, string);

    // Getters and Setters
    
    void setName(string);
    void setSurname(string);

    string getName();
    string getSurname();
};

Person::Person(string Name, string Surname) : name(Name), surname(Surname) {}

void Person::setName(string Name) { name = Name; }
void Person::setSurname(string Surname) { surname = Surname; }

string Person::getName() { return name; }
string Person::getSurname() { return surname; }

#endif
