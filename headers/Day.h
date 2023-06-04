#ifndef DAY_H
#define DAY_H

#include "Event.h"
#include <vector>


class Day
{
private:
    vector<Event> events;
public:
    Day();
    ~Day();
    void addEvent(Event);
    void removeEvent(string);
    int numEvents() const;
};



#endif
