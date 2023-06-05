
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

struct Date
{
    int month;
    int day;
    int year;

    Date(int newMonth, int newDay, int newYear) : month(newMonth), day(newDay), year(newYear) {}

    Date(string date) { 
        /**     
        string monStr = date.substr(0, 2);
        string dayStr = date.substr(3, 2);
        string yrStr = date.substr(6, 4);

        month = stoi(monStr);
        day = stoi(dayStr);
        year = stoi(yrStr);
        */
       std::istringstream iss(date);
       std::string s;
       std::getline(iss, s, '/'); 
       month = stoi(s);
       std::getline(iss, s, '/'); 
       day = stoi(s);
       std::getline(iss, s, '/'); 
       year = stoi(s);
    }

    void printDate() const {
        cout << to_string(month) << "/" <<to_string(day) << "/" << to_string(year);
    }
};
#endif