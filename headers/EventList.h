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

    void displayList() const;
};

EventList::EventList()
{
}

EventList::~EventList()
{
}
