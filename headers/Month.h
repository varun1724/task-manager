#include "Day.h"
#include <string>


class Month
{
private:
    string monthName;
    int year;
    Day *days;
public:
    Month(string, int);
    ~Month();
    void nextMonth() const;
    void prevMonth() const;
private:
    int numDays() const;
    bool isLeapYear() const;
};

Month::Month(string name, int year)
{
    monthName = name;
    this->year = year;
    days = new Day[numDays()];

}

Month::~Month()
{
}
