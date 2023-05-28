#ifndef MONTH_H
#define MONTH_H

#include "Day.h"
#include <string>

using namespace std;


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
private:
    int numDays() const;
    bool isLeapYear() const;
};


Month::Month(int year, string name)
{
    monthName = name;
    this->year = year;
    days = new Day[10];

}

Month::~Month()
{
}

#endif
