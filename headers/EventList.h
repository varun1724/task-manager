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
    void removeEvent(int id);
    void displayList() const;
    void displayNames() const;
    void displayEvent(string);
};

#endif

