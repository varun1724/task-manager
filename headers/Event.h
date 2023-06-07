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
    // A task is the same thing as an event but the only difference is that is shows up in the list
    // under a goal. How do we want to code this?
    bool isTask; 

public:
    Event();
    Event(string, string, Date*, Time*, string);
    ~Event();

    // Getters
    string getName() const;
    string getDescription() const;
    Date* getDate() const;
    Time* getTime() const;
    string getLocation();

    // Setters
    void setName(string);
    void setDescription(string);
    void setDate(Date*);
    void setDate(string date);

    void setTime(Time*);
    void setTime(string time);
    void setLocation(string);

    void printEvent();

};

#endif
