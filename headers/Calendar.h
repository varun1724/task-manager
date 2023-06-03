#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <iostream>

#include "Month.h"
#include "EventList.h"
using namespace std;


class Calendar
{
private:
    Month* curMonth;
    int year;
    EventList list;
public:
    Calendar(int year, string monthName);
    ~Calendar();
    void printCalendar();
};

#endif
