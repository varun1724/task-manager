#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <vector>

using namespace std;

#include "Event.h"

class EventList
{
private:
    vector<Event> events;
public:
    EventList();
    ~EventList();

    void addEvent(Event);
    void removeEvent(string);
    bool findEvent(string) const;
    int findEventNumber(string) const;
    void removeEvent(int id);

    void displayList() const;
    void displayNames() const;
    void displayEvent(string);


    Event& getEvent(int id);
    int getSize() const;

    void setName(string, int);
    void setDate(string, int);
    void setTime(string, int);
    void setDesc(string, int);
    void setlocation(string, int);

    int getLargestTaskId() const;
    bool taskIDExists(int id) const;


};

#endif

