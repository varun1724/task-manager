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


