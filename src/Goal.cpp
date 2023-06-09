#include "../headers/Goal.h"
using namespace std;


Goal:: Goal(string name, string description, string date)
{
    this->name = name;
    this->description = description;
    this->date = date;
    id = 0;
}

Goal::~Goal()
{
    events.~EventList();
}

string Goal::getName() const {
    return name;
}

string Goal::getDescription() const {
    return description;
}

string Goal::getDate() const {
    return date;
}
    
int Goal::getId() const {
    return id;
}

void Goal::setId(int id) {
    this->id = id;
}

void Goal::addEvent(Event event) {
    events.addEvent(event);   
}

void Goal::removeEvent(int id) {
    events.removeEvent(id);
}

void Goal::print() {
    cout << "*********************************" << endl;
    cout << "Goal: " << endl;
    cout << "id: " << id <<endl;
    cout << "name: " << name <<endl;
    cout << "description: " << description<<endl;
    cout << "date: " << date;
    cout << endl;
    cout << endl;
    cout << "Tasks:";
    if (events.getSize() == 0) {
        cout << "You have no tasks for this goal" << endl;
    } else {
        events.displayList();
    }
}

void Goal::setName(string name) {
    this->name = name;
}
void Goal::setDescription(string description) {
    this->description = description;
}
void Goal::setDate(string date) {
    this->date = date;
}
void Goal::setTaskName(int idTask, string name) {
     Event& e = events.getEvent(idTask);
     e.setName(name);
}
void Goal::setTaskDescription(int idTask, string description) {
     Event& e = events.getEvent(idTask);
     e.setDescription(description);
}
void Goal::setTaskDate(int idTask, string date) {
    Event& e = events.getEvent(idTask);
    e.setDate(date);
}
void Goal::setTaskTime(int idTask, string time) {
    Event& e = events.getEvent(idTask);
    e.setTime(time);
}
void Goal::setTaskLocation(int idTask, string location) {
    Event& e = events.getEvent(idTask);
    e.setLocation(location);
}

int Goal::getSize() const {
    return events.getSize();
}

int Goal::getLargestTaskID() const {
    return events.getLargestTaskId();
}

bool Goal::taskIDExists(int id) const {
    return events.taskIDExists(id);
}

Event& Goal::getEvent(int id) {
    return events.getEvent(id);
}

