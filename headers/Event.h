#include "../helper-structs/Time.hpp"

// Modify to have this event
class Event
{
private:
   string name;
   string description;
   // Need date (not yet sure where to put this right now)
   Time time;
   string location;

   // A task is the same thing as an event but the only difference is that is shows up in the list
   // under a goal. How do we want to code this?
   bool isTask; 

public:
    Event(string, string, Time, string);
    ~Event();

    // Getters
    string getName() const;
    string getDescription() const;
    Time getTime() const;
    string getLocation();

    // Setters
    void setName(string);
    void setDescription(string);
    void setTime(Time);
    void setLocation(string);

};

Event::Event(string nm, string des, Time curTime, string loc)
{
    name = nm;
    description = des;
    time = curTime;
    location = loc;
}

Event::~Event()
{
}
