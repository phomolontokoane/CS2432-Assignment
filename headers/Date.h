#ifndef DATE_H
#define DATE_H

class Date {
    private:
        int year, month, day;

    public:
        Date(int,int,int);
        Date(Date&);

        // Getters and Setters
        int getYear();
        int getMonth();
        int getDay();
        void setYear(int y);
        void setMonth(int m);
        void setDay(int d);
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(Date &D): year(D.year), month(D.month), day(D.day) { }

int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }
void Date::setYear(int y) { year = y; }
void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }

#endif