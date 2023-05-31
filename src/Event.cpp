#include "../headers/Event.h"

Event::Event() {
    name = "";
    description = "";
    time = new Time(0, 0);
    location = "";
}


Event::Event(string nm, string des, Time* curTime, string loc)
{
    name = nm;
    description = des;
    time = curTime;
    location = loc;
}

Event::~Event()
{
}
// Getters
string Event::getName() const {
    return name;
}


string Event::getDescription() const {
    return description;
}


Time* Event::getTime() const {
    return time;
}


string Event::getLocation() {
    return location;
}

// Setters
void Event::setName(string newName) {
    name = newName;
}


void Event::setDescription(string newDes) {
    description = newDes;
}


void Event::setTime(Time* newTime) {
    time = newTime;
}


void Event::setLocation(string newLoc) {
    location = newLoc;
}