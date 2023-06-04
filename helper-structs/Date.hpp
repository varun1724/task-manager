#include <iostream>

using namespace std;

struct Date
{
    int month;
    int day;
    int year;

    Date(int newMonth, int newDay, int newYear) : month(newMonth), day(newDay), year(newYear) {}

    Date(string date) {
        
        string monStr = date.substr(0, 2);
        string dayStr = date.substr(3, 2);
        string yrStr = date.substr(6, 4);

        month = stoi(monStr);
        day = stoi(dayStr);
        year = stoi(yrStr);

    }

    void printDate() const {
        cout << month << "/" << day << "/" << year;
    }

};
