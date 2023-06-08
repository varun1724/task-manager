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

void EventList::removeEvent(int id) {
    events.erase(events.begin()+id);
}

void EventList::removeEvent(string name) {
    for (unsigned i = 0; i < events.size(); ++i) {
        if (events.at(i).getName() == name) {
            events.erase(events.begin() + i);
            return;
        }
    }
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
void EventList::displayList() const {

    for (unsigned i = 0; i < events.size(); ++i) {
        Event curEvent = events.at(i);

        cout << endl;

        // Code to print out the goal number

        if (events.at(i).getGoalStatus()) {
            cout << "Task ID: " << events.at(i).getTaskID() << endl;
        }

        curEvent.printEvent();
    }
}


// Displays the names of all the events
void EventList::displayNames() const {

    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
        return;
    }

    for (unsigned i = 0; i < events.size(); ++i) {
        cout << "Task #" << i+1 << ": " << events.at(i).getName() << endl;
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


int EventList::findEventNumber(string name) const {
    for (unsigned i = 0; i < events.size(); ++i) {
        if (name == events.at(i).getName()) {
            return i;
        }
    }

    return 0;
}



// Getters

Event& EventList::getEvent(int id) {
    return events[id];
}


int EventList::getSize() const {
    return events.size();
}


int EventList::getLargestTaskId() const {
    int largest = 0;
    for (unsigned i = 0; i < events.size(); ++i) {
        if (events.at(i).getTaskID() > largest) {
            largest = events.at(i).getTaskID();
        }
    }

    return largest;
}



// Check id a task ID exists within an event
bool EventList::taskIDExists(int id) const {

    for (unsigned i = 0; i < events.size(); ++i) {
        if (events.at(i).getTaskID() == id) {
            return true;
        }
    }

    return false;
}



// Setters
void EventList::setName(string name, int eventNum) {
    events.at(eventNum).setName(name);
}

void EventList::setDate(string date, int eventNum) {
    events.at(eventNum).setDate(date);
}

void EventList::setTime(string time, int eventNum) {
    events.at(eventNum).setTime(time);
}


void EventList::setDesc(string desc, int eventNum) {
    events.at(eventNum).setDescription(desc);
}


void EventList::setlocation(string location, int eventNum) {
    events.at(eventNum).setLocation(location);
}