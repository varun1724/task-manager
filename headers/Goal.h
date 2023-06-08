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
    string date;
    int id;
    EventList events;
public:
    Goal(string name, string description, string date);
    ~Goal();
    string getName() const;
    string getDescription() const;
    string getDate() const;
    int getId() const;
    void setId(int id);
    void addEvent(Event event);
    void removeEvent(int id);
    void print();
    void setName(string name);
    void setDescription(string name);
    void setDate(string date);
    void setTaskName(int idTask, string name);
    void setTaskDescription(int idTask, string name);
    void setTaskDate(int idTask, string date);
    void setTaskTime(int idTask, string time);
    void setTaskLocation(int idTask, string location);

    int getSize() const;
    int getLargestTaskID() const;
    bool taskIDExists(int id) const;
};

#endif
