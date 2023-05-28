#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <iostream>

#include "Month.h"
using namespace std;


class Calendar
{
private:
    Month* curMonth;
    int year;
public:
    Calendar(int, string);
    ~Calendar();
    void printCalendar() const;
};

Calendar::Calendar(int year, string monthName)
{
    curMonth = new Month(year, monthName);
    this->year = year;
}

Calendar::~Calendar()
{
}

#endif
