
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
    Calendar(int year, string monthName);
    ~Calendar();
    void printCalendar();
};

#endif
