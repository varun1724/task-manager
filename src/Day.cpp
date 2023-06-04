#include "../headers/Day.h"
using namespace std;

Day::Day()
{
    
}


// Adds an event to the day
void Day::addEvent(Event newEvent) {
    events.push_back(newEvent);
}

// Searches through the events and removes the one that matches the passed in name
void Day::removeEvent(string eventName) {
    
    for (int i = 0; i < events.size(); ++i) {
        // Still needs completing
    }
}

int Day::numEvents() const {
    return events.size();
}


Day::~Day()
{
}
