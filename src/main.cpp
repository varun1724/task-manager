#include <iostream>

#include "../headers/Calendar.h"
#include "../headers/Event.h"
#include <vector>

using namespace std;

// Event vector helper functions
bool eventIsInList(vector<Event*>&, string);
void displayNames(vector<Event*>&);
Event* findEvent(vector<Event*>&, string);

// Allows the user to add a task to their calendar
int showCreateTaskMenu(vector<Event*> & events) {
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
                events.push_back(new Event(name, desc, new Date(date), new Time(time), location));
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
// TODO - ADD FUNCTIONALITY
int editTaskMenu(vector<Event*> &events) {
    system("clear");
    cout << "Edit Task Menu." << endl;
    cin.clear();
    cin.ignore();
    int goalId;
    //cout << "Enter the Id of goal to which the task belongs:" << endl;
    //cin >> goalId;

    cout << endl;
    cout << "Current Tasks:" << endl;
    displayNames(events);
    cout << endl;

    cout << "Enter the name of the task you would like to edit:" << endl;
    string taskName;
    Event* selectedEvent;
    bool foundName = false;
    while (!foundName) {
        cin >> taskName;
        foundName = eventIsInList(events, taskName);
        if (foundName) {
            selectedEvent = findEvent(events, taskName);
        }
        break;

        cout << "Invalid task name, please try again: " << endl;
    }

    cout << endl;
    cout << "Task Information:" << endl;
    selectedEvent->printEvent();
    cout << endl;

    while (true) {

        cout << endl;
        cout << "What would you like to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Description" << endl;
        cout << "3. Date" << endl;
        cout << "4. Time" << endl;
        cout << "5. Location" << endl;
        cout << "Press any other number to save and exit back to main menu" << endl;

        int input;
        cin >> input;
        cin.ignore();
        if (input == 1) {
            string name;
            cout << "Enter new name:" << endl;
            getline(cin, name);
            selectedEvent->setName(name);
        } else if (input == 2) {
            string desc;
            cout << "Enter new description:" << endl;
            getline(cin, desc);
            selectedEvent->setDescription(desc);
        } else if (input == 3) {
            string date;
            cout << "Enter new date in the format mm/dd/yyyy:" << endl;
            getline(cin, date);
            selectedEvent->setDate(new Date(date));
        } else if (input == 4) {
            string time;
            cout << "Enter new time in format hh:mm:" << endl;
            getline(cin, time);
            selectedEvent->setTime(new Time(time));
        } else if (input == 5) {
            string location;
            cout << "Enter new location" << endl;
            getline(cin, location);
            selectedEvent->setLocation(location);
        } else {
            return 0;
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
int deleteTaskMenu(vector<Event*> &events) {
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




int viewSchedule(vector<Event*> &events) {
    system("clear");
    cout << "View Schedule." << endl;
    cout << "2. Back" << endl;
    int input;
    cin >> input;
    return 0;
}

int createGoal() {
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
    }
    return 0;
}

int editGoal() {
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

int deleteGoal() {
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
        
    }
   
    return 0;
}

int showMainMenu() {

    vector<Event*> events;

    while(true) {
        system("clear");
        cout <<"Main Menu"<<endl;
        cout <<"Select option"<<endl;
        cout <<"1. Create Task"<<endl;
        cout <<"2. Edit Task"<<endl;
        cout <<"3. Delete Task"<<endl;
        cout <<"4. View All Tasks"<<endl;
        cout <<"5. View Schedule"<<endl;
        cout <<"6. Create Goal"<<endl;
        cout <<"7. Edit Goal"<<endl;
        cout <<"8. Delete Goal"<<endl;
        cout <<"9. Exit"<<endl;
        
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
                showTasks(events);
            break;

            case 5:
                //View schedule.
                viewSchedule(events);
            break;

            case 6:
                createGoal();
            break;

            case 7:
                editGoal();
            break;
            
            case 8:
                deleteGoal();
            break;
            
            case 9:

            return 0;

            break;

        }
    }
    return 0;
}

int main() {

    // Calendar cal = Calendar(2023, "May");
    // cal.printCalendar();

    int ret = showMainMenu();
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

