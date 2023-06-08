#include "../headers/Event.h"
#include <iostream>

using namespace std;

Event::Event() {
    name = "";
    description = "";
    date = "";
    time = "";
    location = "";
}


Event::Event(string nm, string des, string curDate, string curTime, string loc)
{
    name = nm;
    description = des;
    date = curDate;
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


string Event::getDate() const {
    return date;
}


string Event::getTime() const {
    return time;
}


string Event::getLocation() const {
    return location;
}


bool Event::getGoalStatus() const {
    return isInGoal;
}


int Event::getTaskID() const {
    return taskID;
}



// Setters
void Event::setName(string newName) {
    name = newName;
}


void Event::setDescription(string newDes) {
    description = newDes;
}


void Event::setDate(string newDate) {
    date = newDate;
}


void Event::setTime(string newTime) {
    time = newTime;
}

void Event::setLocation(string newLoc) {
    location = newLoc;
}


void Event::setGoalStatus(bool status) {
    isInGoal = status;
}


void Event::setTaskID(int id) {
    taskID = id;
}


void Event::printEvent() {

    cout << "Name: " << name << ", " << date << " " << time << " at " << location << endl;
    cout << "Description: " << description << endl;
}