#include "../headers/Event.h"
#include <iostream>

using namespace std;

Event::Event() {
    name = "";
    description = "";
    date = new Date(0, 0, 1000);
    time = new Time(0, 0);
    location = "";
}


Event::Event(string nm, string des, Date* curDate, Time* curTime, string loc)
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


Date* Event::getDate() const {
    return date;
}


Time* Event::getTime() const {
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


void Event::setDate(Date* newDate) {
    date = newDate;
}

void Event::setDate(string dt) {
    delete date;
    date = new Date(dt);
}

void Event::setTime(Time* newTime) {
    time = newTime;
}

void Event::setTime(string t) {
    delete time;
    time = new Time(t);
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

    cout << "Name: " << name << ", "; 
    date->printDate();
    cout << " "; 
    time->printTime();
    cout << " at " << location << endl;

    cout << "Description: " << description << endl;
}