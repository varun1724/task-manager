#include "../headers/EventList.h"
#include <string.h>


EventList::EventList()
{
}

EventList::~EventList()
{
}


void EventList::addEvent(Event newEvent) {
    events.push_back(newEvent);
}

void EventList::removeEvent(string name) {

}


bool EventList::findEvent(string name) const {

    for (unsigned i = 0; i < events.size(); ++i) {
        if (name == events.at(i).getName()) {
            return true;
            break;
        }
    }
    return false;
}


// Displays all events and their information
// TODO - REFACTOR THIS CODE TO USE THE DISPLAYEVENT FUNCTION LOCATED IN THE EVENT CLASS
void EventList::displayList() const {

    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
        return;
    }

    for (unsigned i = 0; i < events.size(); ++i) {
        Event curEvent = events.at(i);

        cout << endl;

        cout << "Event #" << i+1 << ": " << curEvent.getName() << ", "; 
        curEvent.getDate()->printDate();
        cout << " "; 
        curEvent.getTime()->printTime();
        cout << " at " << curEvent.getLocation() << endl;

        cout << "Description: " << curEvent.getDescription() << endl;
    }
}


// Displays the names of all the events
void EventList::displayNames() const {

    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
        return;
    }

    for (unsigned i = 0; i < events.size(); ++i) {
        cout << "Event #" << i+1 << ": " << events.at(i).getName() << endl;
    }
}

// Displays the information of a single event
void EventList::displayEvent(string name) {
    for (unsigned i = 0; i < events.size(); ++i) {
        if (name == events.at(i).getName()) {
            events.at(i).printEvent();
        }
    }
}
