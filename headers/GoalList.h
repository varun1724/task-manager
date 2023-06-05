#ifndef GOALLIST_H
#define GOALLIST_H
#include <vector>
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
};

#endif
