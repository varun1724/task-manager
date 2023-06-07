#include "../headers/Goal.h"
#include "../headers/GoalList.h"

using namespace std;


GoalList::GoalList(/* args */)
{
    currentId = 0;
}

GoalList::~GoalList()
{

}

void GoalList::addGoal(Goal goal) {
    currentId++;
    goal.setId(currentId);
    goals.push_back(goal);
}

void GoalList::removeGoal(int id) {
    for(int i = 0; i < goals.size(); i++){
        if(goals[i].getId() == id) {
            goals.erase(goals.begin()+i);
            break;
        }
    }
}

void GoalList::print(){
    for(int i = 0; i < goals.size(); i++){
       goals[i].print();
    }
}

void GoalList::addEvent(int id, Event event) {
    for(int i =0; i < goals.size(); i++) {
        if(id == goals[i].getId()) {
            goals[i].addEvent(event);
            break;
        }
    }
}

void GoalList::removeEvent(int idGoal, int idEvent) {
    for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].removeEvent(idEvent);
            break;
        }
    }
}

void GoalList::setGoalName(int id, string name) {
    for(int i =0; i < goals.size(); i++) {
        if(id == goals[i].getId()) {
            goals[i].setName(name);
            break;
        }
    }
}

void GoalList::setGoalDescription(int id, string description) {
    for(int i =0; i < goals.size(); i++) {
        if(id == goals[i].getId()) {
            goals[i].setDescription(description);
            break;
        }
    }
}

void GoalList::setGoalDate(int id, string date) {
    for(int i =0; i < goals.size(); i++) {
        if(id == goals[i].getId()) {
            goals[i].setDate(date);
            break;
        }
    }
}

void GoalList::setTaskName(int idGoal, int idTask, string name) {
   for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].setTaskName(idTask, name);
            break;
        }
    }
}
void  GoalList::setTaskDescription(int idGoal, int idTask, string description) {
    for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].setTaskDescription(idTask, description);
            break;
        }
    }
}
void  GoalList::setTaskDate(int idGoal, int idTask, string date) {
    for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].setTaskDate(idTask, date);
            break;
        }
    }
}
void  GoalList::setTaskTime(int idGoal, int idTask, string time) {
    for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].setTaskTime(idTask, time);
            break;
        }
    }
}
void  GoalList::setTaskLocation(int idGoal, int idTask, string location) {
    for(int i =0; i < goals.size(); i++) {
        if(idGoal == goals[i].getId()) {
            goals[i].setTaskLocation(idTask, location);
            break;
        }
    }
}
