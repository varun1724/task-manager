#include <iostream>

using namespace std;

struct Time {
    int hour;
    int minutes;

    Time(int inputHour, int inputMinutes) : hour(inputHour), minutes(inputMinutes) {};

    Time(string t) {
        
        string hourStr = t.substr(0, 2);
        string minStr = t.substr(3, 2);

        hour = stoi(hourStr);
        minutes = stoi(minStr);

    }
    
    void printTime() const {
        cout << hour << ":" << minutes;
    }
};