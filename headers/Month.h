#ifndef MONTH_H
#define MONTH_H

#include "Day.h"
#include <string>


class Month
{
private:
    string monthName;
    int year;
    Day *days;
public:
    Month(int, string);
    ~Month();
    void nextMonth();
    void prevMonth();
    int numDays() const;
    string getMonthName();
private:
    bool isLeapYear() const;
};




#endif
