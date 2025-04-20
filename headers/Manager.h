#ifndef MANGER_H
#define MANGER_H

#include <iostream>
#include "Person.h"
using std::string;

class Manager : public Person
{
private:
    int emply_num;
    int rank;

public:
    Manager(string, string, int, int);

    // Getters and Setters

    int getId();
    int getRank();

    void setId(int);
    void setRank(int);

    // Operators
    Manager &operator=(Manager &);
};

Manager::Manager(string Name, string Surname, int id, int Rank)
    : Person(Name, Surname), emply_num(id), rank(Rank) {}

int Manager::getId() { return emply_num; }
int Manager::getRank() { return rank; }

void Manager::setId(int id) { emply_num = id; }
void Manager::setRank(int Rank) { rank = Rank; }

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