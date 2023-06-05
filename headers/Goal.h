#ifndef GOAL_H
#define GOAL_H
#include "EventList.h"
#include "../helper-structs/Time.hpp"
#include "../helper-structs/Date.hpp"
#include <string>

using namespace std;

class Goal
{
private:
    string name;
    string description;
    Date* date;
    int id;
    EventList events;
public:
    Goal(string name, string description, Date *date);
    ~Goal();
    string getName();
    string getDescription();
    Date* getDate();
    int getId();
    void setId(int id);
    void addEvent(Event event);
    void removeEvent(int id);
};

#endif
