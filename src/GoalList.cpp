#include "../headers/Goal.h"
#include "../headers/GoalList.h"

using namespace std;


GoalList::GoalList()
{
    currentId = 0;
}

GoalList::~GoalList()
{
    goals.clear();
    goals.shrink_to_fit();
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
            goals.shrink_to_fit();
            break;
        }
    }
}


void GoalList::addEvent(int id, Event event) {
    for(int i =0; i < goals.size(); i++) {
        if(id == goals[i].getId()) {
            event.setGoalStatus(true);
            if (goals.at(i).getSize() == 0) {
                event.setTaskID(0);
            } else {
                event.setTaskID(goals.at(i).getLargestTaskID()+1);
            }
            
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


// Setters

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


// Helper functions with ID and Size

bool GoalList::idExists(int id) const {
    for (unsigned i = 0; i < goals.size(); ++i) {
        if (goals.at(i).getId() == id) {
            return true;
        }
    }

    return false;
}


int GoalList::getSize() const {
    return goals.size();
}

int GoalList::getTasksSize(int goalID) const {
    for (unsigned i = 0; i < goals.size(); ++i) {
        if (goals.at(i).getId() == goalID) {
            return goals.at(i).getSize();
        }
    }
    return 0;
}


 bool GoalList::taskIDExists(int id, int goalID) const {
    for (unsigned i = 0; i < goals.size(); ++i) {
        if (goals.at(i).getId() == goalID) {
            if (goals.at(i).taskIDExists(id)) {
                return true;
            }
        }
    }

    return false;
 }

Goal& GoalList::getGoal(int id) {
    int j = 0;
    for (unsigned i = 0; i < goals.size(); ++i) {
        if (goals.at(i).getId() == id) {
            j = i;
        }
    }
    return goals.at(j);
}

Event& GoalList::getEvent(int idGoal, int idTask) {
    Goal& goal = getGoal(idGoal);
    return goal.getEvent(idTask);
}


// Print

void GoalList::print() {
    for (int i = 0; i < goals.size(); i++){
       goals[i].print();
    }
}

