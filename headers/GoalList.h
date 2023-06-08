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
    GoalList();
    ~GoalList();


    void addGoal(Goal goal);
    void removeGoal(int id);

    
    void addEvent(int id, Event event);
    void removeEvent(int idGoal, int idEvent);

    // Setters
    void setGoalName(int id, string name);
    void setGoalDescription(int id, string description);
    void setGoalDate(int id, string date);
    void setTaskName(int idGoal, int idTask, string name);
    void setTaskDescription(int idGoal, int idTask, string name);
    void setTaskDate(int idGoal, int idTask, string date);
    void setTaskTime(int idGoal, int idTask, string time);
    void setTaskLocation(int idGoal, int idTask, string location);

    bool idExists(int id) const;
    int getSize() const;
    int getTasksSize(int) const;
    bool taskIDExists(int id, int goalID) const;
    Goal& getGoal(int id);
    Event& getEvent(int idGoal, int idTask);
    void print();
     
};

#endif
