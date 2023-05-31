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
};

Day::Day()
{
    
}

Day::~Day()
{
}
