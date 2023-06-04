#include "../headers/EventList.h"


void EventList::addEvent(Event newEvent) {
    events.push_back(newEvent);
}

void EventList::removeEvent(string name) {

}

void EventList::displayList() const {

    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
        return;
    }

    for (int i = 0; i < events.size(); ++i) {
        Event curEvent = events.at(i);

        cout << endl;

        cout << "Event #" << i+1 << ": " << curEvent.getName() << ", "; 
        curEvent.getDate()->printDate();
        cout << " "; 
        curEvent.getTime()->printTime() ;
        cout << "at " << curEvent.getLocation() << endl;

        cout << curEvent.getDescription() << endl;
        cout << endl;
    }
}

EventList::EventList()
{
}

EventList::~EventList()
{
}