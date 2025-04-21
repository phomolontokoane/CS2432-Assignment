#ifndef STUDENTS_H
#define STUDENTS_H

#include "Person.h"

class Student: public Person
{
private:
    int std_no;
    string faculty;
public:
    Student(string, string, int, string);
    Student(Student&);

    // Getters and Setters

    int getStdNo();
    string getFaculty();

    void setStdNo(int);
    void setFaculty(string);

    Student& operator=(Student&);

    void display();
};

Student::Student(string Name, string Surname, int id, string Faculty)
: Person(Name, Surname), std_no(id), faculty(Faculty) {}

Student::Student(Student &S): Person(S.getName(), S.getSurname())
{
    std_no = S.std_no;
    faculty = S.faculty;
}

int Student::getStdNo() { return std_no; }
string Student::getFaculty() { return faculty; }

void Student::setStdNo(int id) { std_no = id; }
void Student::setFaculty(string Faculty) { faculty = Faculty; }

Student& Student::operator=(Student &S)
{
    if (this != &S) {
        setName(S.getName());
        setSurname(S.getSurname());
        std_no = S.std_no;
        faculty = S.faculty;
    }
    return *this;
}

void Student::display()
{
    std::cout << "Name: " << getName() << " " << getSurname() << "\n";
    std::cout << "Student Number: " << std_no << "\n";
    std::cout << "Faculty: " << faculty << "\n";
}

#endif