#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
using namespace std;
// Modify to have this event
class Event
{
private:
    string name;
    string description;
    string date;
    string time;
    string location;
    bool isInGoal = false; 
    int taskID = 0;

public:
    Event();
    Event(string name, string description, string date, string time, string location);
    ~Event();

    // Getters
    string getName() const;
    string getDescription() const;
    string getDate() const;
    string getTime() const;
    string getLocation() const;

    bool getGoalStatus() const;
    int getTaskID() const;

    // Setters
    void setName(string);
    void setDescription(string);
    void setDate(string);

    void setTime(string);

    void setLocation(string);

    void setGoalStatus(bool);
    void setTaskID(int);

    void printEvent();

};

#endif
