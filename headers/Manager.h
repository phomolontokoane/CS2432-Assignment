#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Person.h"
using std::string;
using std::cout;

class Manager : public Person
{
private:
    string emply_num;
    int rank;

public:
    Manager(string, string, string, int);

    // Getters and Setters
    string getId();
    int getRank();

    void setId(string);
    void setRank(int);

    // Display function
    void display();

    // Operators
    Manager &operator=(Manager &);
};

Manager::Manager(string Name, string Surname, string id, int Rank)
    : Person(Name, Surname), emply_num(id), rank(Rank) {}

string Manager::getId() { return emply_num; }
int Manager::getRank() { return rank; }

void Manager::setId(string id) { emply_num = id; }
void Manager::setRank(int Rank) { rank = Rank; }

void Manager::display()
{
    cout << "Manager Name: " << getName() << " " << getSurname() << "\n";
    cout << "Employee ID: " << emply_num << "\n";
    cout << "Rank: " << rank << "\n\n";
}

Manager &Manager::operator=(Manager &M)
{
    if (this != &M)
    {
        setName(M.getName());
        setSurname(M.getSurname());
        emply_num = M.emply_num;
        rank = M.rank;
    }

    return *this;
}

#endif