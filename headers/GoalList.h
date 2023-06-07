#ifndef GOALLIST_H
#define GOALLIST_H
#include <vector>
#include "Event.h"
using namespace std;

class GoalList
{
private:
    vector<Goal> goals;
    int currentId;
public:
    GoalList(/* args */);
    ~GoalList();
    void addGoal(Goal goal);
    void removeGoal(int id);
    void print();
    void addEvent(int id, Event event);
    void removeEvent(int idGoal, int idEvent);
    void setGoalName(int id, string name);
    void setGoalDescription(int id, string description);
    void setGoalDate(int id, string date);
    void setTaskName(int idGoal, int idTask, string name);
    void setTaskDescription(int idGoal, int idTask, string name);
    void setTaskDate(int idGoal, int idTask, string date);
    void setTaskTime(int idGoal, int idTask, string time);
    void setTaskLocation(int idGoal, int idTask, string location);
     
};

#endif
