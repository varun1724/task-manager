
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

struct Date
{
    string date;

    Date(string entryDate) { 
        date = entryDate;
    }

};
#endif