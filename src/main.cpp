#include <iostream>

#include "../headers/Calendar.h"
#include "../headers/Goal.h"
#include "../headers/GoalList.h"

using namespace std;

int showCreateTaskMenu(EventList& events) {
    while(true) {
        system("clear");
        cout << "Create Task Menu." << endl;
        cout << "1. Add New Task." << endl;
        cout << "2. Back" << endl;
        int input;
        cin >> input;
        if(input == 1) {
            string name;
            string desc;
            string date;
            string time;
            string location;

            cout << "Enter Event or Task Name:" << endl;
            cin.ignore();
            getline(cin, name);

            cout << "Enter Description:" << endl;
            getline(cin, desc);

            cout << "Enter Date in the format mm/dd/yyyy:" << endl; 
            getline(cin, date); // Make sure that the time is entered in the valid format here or the function will not work

            cout << "Enter Time in format hh:mm:" << endl;
            getline(cin, time); // Make sure user enters valid time here, if they dont then prompt to enter again until correct format

            cout << "Enter location:" << endl;
            getline(cin, location);

            cout << "1. Save" << endl;
            cout << "2. Cancel" << endl;

            cin >> input;

            if (input == 1) {
                events.addEvent(Event(name, desc, new Date(date), new Time(time), location));
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 0;
}
int editTaskMenu(EventList &events) {
    system("clear");
    cout << "Edit Task Menu." << endl;
    cin.clear();
    cin.ignore();
    int goalId;
    int taskId;
    cout << "Enter the Id of goal to which the task belongs:" << endl;
    cin >> goalId;
    cout << "Enter the Id of task:" << endl;
    cin >> taskId;
    string name;
    string desc;
    string date;
    string time;
    cout << "Enter Event or Task Name:" << endl;
    cin >> name;
    cout << "Enter Description:" << endl;
    cin >> desc;
    cout << "Enter Date:" << endl;
    cin >> date;
    cout << "Enter Time:" << endl;
    cin >> time;
    cout << "1. Save" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    return 0;
}
int deleteTaskMenu(EventList &events) {
    system("clear");
    cin.clear();
    cin.ignore();
    int goalId;
    int taskId;
    cout << "Delete Task Menu." << endl;
    cout << "Enter the Id of goal to which the task belongs:" << endl;
    cin >> goalId;
    cout << "Enter the Id of task:" << endl;
    cin >> taskId;
    cout << "1. Confirm delete" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    if(1 == input) {
        cout << "Deleted" << endl;
    }
    return 0;
}

int viewSchedule(GoalList& goals, EventList &events) {
    system("clear");
    cout << "View Schedule." << endl;
    goals.print();
    cout << "2. Back" << endl;
    int input;
    cin >> input;
    return 0;
}

int createGoal(GoalList& goals) {
    system("clear");
    cout << "Create Goal Menu." << endl;
    string name;
    string des;
    string date;
    cin.clear();
    cin.ignore();
    cout << "Enter name of the goal:" << endl;
    getline(cin, name);
    cout << "Enter description of the goal:" << endl;
    getline(cin, des);
    cout << "Enter due date of goal:" << endl; 
    getline(cin, date);
    cout << "1. Save" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    if(1 == input) {
        //save the goal.
        Date *dt = new Date(date);
        Goal *goal = new Goal(name, des, dt);
        goals.addGoal(*goal);
    }
    return 0;
}

int editGoal(GoalList& goals) {
    system("clear");
    cout << "Edit Goal Menu." << endl;
    //Show the goal list.
    cin.clear();
    cin.ignore();
    int id;
    string name;
    string des;
    string date;
    cout << "Enter the Id of Goal to edit:" << endl;
    cin >> id;
    cin.ignore();
    cout << "Enter name of the goal:" << endl;
    getline(cin, name);
    cout << "Enter description of the goal:" << endl;
    getline(cin, des);
    cout << "Enter due date of goal:" << endl; 
    getline(cin, date);
    cout << "1. Save" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    if(1 == input) {
        //save the goal.
    } 
    return 0;
}

int deleteGoal(GoalList& goals) {
    system("clear");
    cout << "Delete Goal Menu." << endl;
    //Show the goal list
    int id;
    cout << "Enter the Id of Goal to delet:" << endl;
    cin >> id;
    cout << "1. Confirm delete" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    if(1 == input) {
        goals.removeGoal(id);
    }
    return 0;
}

int showMainMenu() {

    EventList events;
    GoalList goals;

    while(true) {
        system("clear");
        cout <<"Main Menu"<<endl;
        cout <<"Select option"<<endl;
        cout <<"1. Create Task"<<endl;
        cout <<"2. Edit Task"<<endl;
        cout <<"3. Delete Task"<<endl;
        cout <<"4. View Schedule"<<endl;
        cout <<"5. Create Goal"<<endl;
        cout <<"6. Edit Goal"<<endl;
        cout <<"7. Delete Goal"<<endl;
        cout <<"8. Exit"<<endl;
        
        int input;
        cin >> input;
        switch (input){
            case 1:
                //Show create task menu.
                showCreateTaskMenu(events);
            break;

            case 2:
                //Edit task menu.
                editTaskMenu(events);
            break;

            case 3:
                //Show delete task menu.
                deleteTaskMenu(events);
            break;

            case 4:
                //View schedule.
                viewSchedule(goals, events);
            break;

            case 5:
                createGoal(goals);
            break;

            case 6:
                editGoal(goals);
            break;
            
            case 7:
                deleteGoal(goals);
            break;
            
            case 8:

            return 0;

            break;

        }
    }
    return 0;
}

int main() {
    int ret = showMainMenu();
    cout << "Exiting " << endl;
    return 0;
}



