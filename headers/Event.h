#ifndef EVENT_H
#define EVENT_H

#include "../helper-structs/Time.hpp"
#include "../helper-structs/Date.hpp"
#include <string>

// Modify to have this event
class Event
{
private:
    string name;
    string description;
    Date* date;
    Time* time;
    string location;
    bool isInGoal = false; 
    int taskID = 0;

public:
    Event();
    Event(string, string, Date*, Time*, string);
    ~Event();

    // Getters
    string getName() const;
    string getDescription() const;
    Date* getDate() const;
    Time* getTime() const;
    string getLocation() const;

    bool getGoalStatus() const;
    int getTaskID() const;

    // Setters
    void setName(string);
    void setDescription(string);
    void setDate(Date*);
    void setDate(string date);

    void setTime(Time*);
    void setTime(string time);

    void setLocation(string);

    void setGoalStatus(bool);
    void setTaskID(int);

    void printEvent();

};

#endif
