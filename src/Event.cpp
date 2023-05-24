#include "../headers/Event.h"


// Getters
string Event::getName() const {
    return name;
}


string Event::getDescription() const {
    return description;
}


Time Event::getTime() const {
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


void Event::setTime(Time newTime) {
    time = newTime;
}


void Event::setLocation(string newloc) {
    location = newLoc;
}