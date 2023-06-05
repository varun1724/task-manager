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
        cout << "*********************************" << endl;
        cout << "Goal: " << endl;
        cout << "id: " << goals[i].getId()<<endl;
        cout << "name: " << goals[i].getName()<<endl;
        cout << "description: " << goals[i].getDescription()<<endl;
        cout << "date: ";
        goals[i].getDate()->printDate();
        cout << endl;
        cout << "*********************************" << endl;
    }
}