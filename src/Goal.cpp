#include "../headers/Goal.h"
using namespace std;


Goal:: Goal(string name, string description, Date *date)
{
    this->name = name;
    this->description = description;
    this->date = date;
    id = 0;
}

Goal::~Goal()
{
    
}

string Goal::getName() {
    return name;
}

string Goal::getDescription() {
    return description;
}

Date* Goal::getDate() {
    return date;
}
    
int Goal::getId() {
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
    cout << "date: ";
    date->printDate();
    cout << endl;
    cout << endl;
    cout << "Tasks:" << endl;
    events.displayList();
    cout << "*********************************" << endl;
}

void Goal::setName(string name) {
    this->name = name;
}
void Goal::setDescription(string description) {
    this->description = description;
}
void Goal::setDate(string date) {
    delete this->date;
    this->date = new Date(date);
}
void Goal::setTaskName(int idTask, string name) {
     Event& e = events.getEvent(idTask - 1);
     e.setName(name);
}
void Goal::setTaskDescription(int idTask, string description) {
     Event& e = events.getEvent(idTask - 1);
     e.setDescription(description);
}
void Goal::setTaskDate(int idTask, string date) {
    Event& e = events.getEvent(idTask - 1);
    e.setDate(date);
}
void Goal::setTaskTime(int idTask, string time) {
    Event& e = events.getEvent(idTask - 1);
    e.setTime(time);
}
void Goal::setTaskLocation(int idTask, string location) {
    Event& e = events.getEvent(idTask - 1);
    e.setLocation(location);
}


