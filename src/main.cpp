#include <iostream>

#include "../headers/Calendar.h"
#include "../headers/Event.h"
#include "../headers/Goal.h"
#include "../headers/GoalList.h"
#include <vector>

using namespace std;

// Event vector helper functions
bool eventIsInList(vector<Event*>&, string);
void displayNames(vector<Event*>&);
Event* findEvent(vector<Event*>&, string);

// Allows the user to add a task to their calendar
int showCreateTaskMenu(GoalList& goals, vector<Event*> & events) {
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

            cout << "Enter Id of goal:" << endl;
            int id;
            cin >> id;

            cout << "1. Save" << endl;
            cout << "2. Cancel" << endl;

            cin >> input;

            if (input == 1) {
                Event* event = new Event(name, desc, new Date(date), new Time(time), location);
                goals.addEvent(id, *event);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 0;
}


// Allows a user to edit specific tasks
int editTaskMenu(GoalList& goals, vector<Event*> &events) {
    system("clear");
    cout << "Edit Task Menu." << endl;
    cin.clear();
    cin.ignore();
    cout << "Current goals:" << endl;
    goals.print();
    int idGoal;
    int idTask;
    cout << "Enter the Id of goal:" << endl;
    cin >> idGoal;
    cout << "Enter the Id of Task to be edited:" << endl;
    cin >> idTask;
    while(true) {
        cout << endl;
        cout << "What would you like to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Description" << endl;
        cout << "3. Date" << endl;
        cout << "4. Time" << endl;
        cout << "5. Location" << endl;
        cout << "Press any other number to save and exit back to main menu" << endl;

        int option;
        cin >> option;
        cin.ignore();
        string name;
        string desc;
        string date;
        string time;
        string location;
        switch(option) {
            case 1:
                cout << "Enter new name:" << endl;
                getline(cin, name);
            break;
            case 2:
                cout << "Enter new description:" << endl;
                getline(cin, desc);
            break;
            case 3:
                cout << "Enter new date in the format mm/dd/yyyy:" << endl;
                getline(cin, date);
            break;
            case 4:
                cout << "Enter new time in format hh:mm:" << endl;
                getline(cin, time);
            break;
            case 5:
                cout << "Enter new location" << endl;
                getline(cin, location);
            break;
        }
        cout << "1. Save" << endl;
        cout << "2. Cancel" << endl;
        int input;
        cin >> input;
        if (input == 1) {
            switch(option) {
                case 1:
                    goals.setTaskName(idGoal, idTask, name);
                break;
                case 2:
                    goals.setTaskDescription(idGoal, idTask, desc);
                break;
                case 3:
                    goals.setTaskDate(idGoal, idTask, date);
                break;
                case 4:
                    goals.setTaskTime(idGoal, idTask, time);
                break;
                case 5:
                    goals.setTaskLocation(idGoal, idTask, location);
                break;
            }
        }
        cout << endl;
        cout << "Would you like to change anything else?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> input;
        if (input == 2) {
            return 0;
        }
    }

    return 0;
}

// Deletes a task from the list
// TODO - ADD THE DELETE FUNCTIONALITY
int deleteTaskMenu(GoalList& goals, vector<Event*> &events) {
    system("clear");
    cin.clear();
    cin.ignore();
    cout << "Current goals:" << endl;
    goals.print();
    int idGoal;
    int idTask;
    cout << "Enter the Id of goal:" << endl;
    cin >> idGoal;

    cout << "Enter the Id of Task to be deleted:" << endl;
    cin >> idTask;
    
    cout << "1. Confirm delete" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    if(1 == input) {
        goals.removeEvent(idGoal, idTask);
    }
    return 0;
}


// Displays all the tasks the user has 
// TODO - MAKE THE LIST PRINT IN CHRONOLOGICAL ORDER 
int showTasks(vector<Event*> &events) {
    system("clear");

    cout << "Press any number to return to main menu" << endl;
    
    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
    } else {
        for (unsigned i = 0; i < events.size(); ++i) {
            Event* curEvent = events.at(i);

            cout << endl;

            cout << "Event #" << i+1 << ": " << curEvent->getName() << ", "; 
            curEvent->getDate()->printDate();
            cout << " "; 
            curEvent->getTime()->printTime();
            cout << " at " << curEvent->getLocation() << endl;

            cout << "Description: " << curEvent->getDescription() << endl;
        }
    }

    int input;
    cin >> input;

    return 0;
}



int viewSchedule(Calendar calendar,GoalList& goals,vector<Event*> &events) {
    system("clear");
    cout << "View Schedule." << endl;
    calendar.printCalendar();
    cout << "1. Next Month" << endl;
    cout << "2. Previous Month" << endl;
    cout << "3. Select Date" << endl;
    int input;
    cin >> input;
    if(input == 1){
        calendar.nextCalMonth();
        viewSchedule(calendar,goals,events);
    }
    else if(input == 2){
        calendar.prevCalMonth();
        viewSchedule(calendar,goals,events);
    }
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
    cout << "Enter due date in the format mm/dd/yyyy:" << endl; 
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
    cout << "Current goals:" << endl;
    goals.print();
    //Show the goal list.
    cin.clear();
    cin.ignore();
    int id;
    string name;
    string des;
    string date;
    cout << "Enter the Id of Goal to edit:" << endl;
    cin >> id;
    while(true) {
        cin.ignore();
        cout << endl;
        cout << "What would you like to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Description" << endl;
        cout << "3. Date" << endl;
        int option;
        cin >> option;
        cin.ignore();
        switch(option) {
            case 1:
                cout << "Enter new name of the goal:" << endl;
                getline(cin, name);
            break;
            case 2:
                cout << "Enter new description of the goal:" << endl;
                getline(cin, des);
            break;    
            case 3:
                cout << "Enter new due date in the format mm/dd/yyyy:" << endl; 
                getline(cin, date);
            break;
        }
        cout << "1. Save" << endl;
        cout << "2. Cancel" << endl;
        int input;
        cin >> input;
        if(1 == input) {
            switch(option) {
                case 1:    
                    goals.setGoalName(id, name);
                break;
                case 2:
                    goals.setGoalDescription(id, des);
                break;    
                case 3:
                    goals.setGoalDate(id, date);
                break;
            }
        } 
        cout << endl;
        cout << "Would you like to change anything else?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> input;
        if (input == 2) {
            return 0;
        }
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

    vector<Event*> events;
    GoalList goals;
    Calendar calendar(2023,"February");
    while(true) {
        system("clear");
        cout <<"Main Menu"<<endl;
        cout <<"Select option"<<endl;
        cout <<"1. Create Goal"<<endl;
        cout <<"2. Edit Goal"<<endl;
        cout <<"3. Delete Goal"<<endl;
        cout <<"4. Create Task"<<endl;
        cout <<"5. Edit Task"<<endl;
        cout <<"6. Delete Task"<<endl;
        cout <<"7. View Schedule"<<endl;
        cout <<"8. Exit"<<endl;
        
        int input;
        cin >> input;
        switch (input){
            case 1:
                createGoal(goals);
            break;

            case 2:
                editGoal(goals);
            break;

            case 3:
                deleteGoal(goals);
            break;

            case 4:
                showCreateTaskMenu(goals, events);
            break;

            case 5:
                editTaskMenu(goals, events);
            break;

            case 6:
                deleteTaskMenu(goals, events);
            break;

            case 7:
                viewSchedule(calendar, goals, events);
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




/////////////////////////////
// Vector functions
/////////////////////////////


// Searches for a specific event by name
// If found, return true, false if not
bool eventIsInList(vector<Event*>& events, string name) {

     for (unsigned i = 0; i < events.size(); ++i) {
        if (name == events.at(i)->getName()) {
            return true;
            break;
        }
    }
    return false;
}

Event* findEvent(vector<Event*>& events, string name) {

    for (unsigned i = 0; i < events.size(); ++i) {
        if (name == events.at(i)->getName()) {
            return events.at(i);
            break;
        }
    }

    // May want to change this case here
    return new Event();

}


// Displays the names of all events
void displayNames(vector<Event*> & events) {

    if (events.size() == 0) {
        cout << "You have no upcoming events" << endl;
        return;
    }

    for (unsigned i = 0; i < events.size(); ++i) {
        cout << "Event #" << i+1 << ": " << events.at(i)->getName() << endl;
    }
}

