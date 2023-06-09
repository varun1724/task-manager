#include <iostream>

#include "../headers/Goal.h"
#include "../headers/Event.h"
#include "../headers/EventList.h"
#include "../headers/GoalList.h"
#include <vector>
#include <limits>

using namespace std;

void viewFormatting(GoalList&, EventList&);

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// EDIT TASK MENU
// Can edit tasks that are either in or outside a goal
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int showCreateTaskMenu(GoalList& goals, EventList& events) {  //Input Validation Done
    while(true) {
        system("clear");
        cout << "Create Task Menu." << endl;
        cout << "1. Add New Task." << endl;
        cout << "2. Back" << endl;
        int input;
        cin >> input;

        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }

        if(input == 1) {
            string name;
            string desc;
            string date;
            string time;
            string location;

            cout << "Enter Task Name:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin, name);

            cout << "Enter Description:" << endl;
            getline(cin, desc);

            cout << "Enter Date in the format mm/dd/yyyy:" << endl; 
            getline(cin, date); // Make sure that the time is entered in the valid format here or the function will not work

            cout << "Enter Time in format hh:mm:" << endl;
            getline(cin, time); // Make sure user enters valid time here, if they dont then prompt to enter again until correct format

            cout << "Enter location:" << endl;
            getline(cin, location);

            cout << "Enter Id of goal (Enter an existing goal's id associate it with a goal or it will be unassigned):" << endl;
            int id;
            cin >> id;

            cout << "1. Save" << endl;
            cout << "2. Cancel" << endl;
            
            cin >> input;

            //Input Validation
            while(true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Please enter a numeric input"<<endl;
                    cin >> input;
                }
                if(input != 1 && input != 2){
                    cout<<"Please enter a valid input"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> input;
                }
                if(!cin.fail()){
                    break;
                }
            }

            if (input == 1) {
                Event* event = new Event(name, desc, date, time, location);

                if (goals.idExists(id)) {
                    goals.addEvent(id, *event);
                } else {
                    events.addEvent(*event);
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 0;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// EDIT TASK MENU
// Can edit tasks that are either in or outside a goal
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////



int editTaskMenu(GoalList& goals, EventList &events) { //Validated Input
    system("clear");
    cout << "Edit Task Menu." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Current Tasks" << endl;
    viewFormatting(goals, events);


    int choice;
    cout << "Would you like to edit a task that is associated with a goal?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;

    //Input Validation
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter a numeric input"<<endl;
            cin >> choice;
        }
        if(choice != 1 && choice != 2){
            cout<<"Please enter a valid input"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> choice;
        }
        if(!cin.fail()){
            break;
        }
    }    

    ////////////////////////////////
    // EDITING TASKS NOT WITHIN A GOAL
    ////////////////////////////////

    if (choice == 2) {

        if (events.getSize() == 0) {
            cout << "You have no tasks outside goals" << endl;
            cout << "Press any key to return to main menu" << endl;
            int in;
            cin >> in;
            return 0;
        }

        string name;
        cout << "Enter the name of the event you would like to edit" << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        bool foundEvent = false;
        int eventNum;
        while(!foundEvent) {
            getline(cin, name);

            if (events.findEvent(name)) {
                foundEvent = true;
                eventNum = events.findEventNumber(name);
            } else {
                cout << "Invalid name, please try again" << endl;
            }
        }

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
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
 
            string name;
            string desc;
            string date;
            string time;
            string location;
            if (option == 1) {
                cout << "Enter new name:" << endl;
                getline(cin, name);
            } else if (option == 2) {
                cout << "Enter new description:" << endl;
                getline(cin, desc);
            } else if (option == 3) {
                cout << "Enter new date in the format mm/dd/yyyy:" << endl;
                getline(cin, date);
            } else if (option == 4) {
                cout << "Enter new time in format hh:mm:" << endl;
                getline(cin, time);
            } else if (option == 5) {
                cout << "Enter new location" << endl;
                getline(cin, location);
            } else {
                return 0;
            }


            cout << "1. Save" << endl;
            cout << "2. Cancel" << endl;
            int input;
            cin >> input;
            //Input Validation
            while(true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Please enter a numeric input"<<endl;
                    cin >> input;
                }
                if(input != 1 && input != 2){
                    cout<<"Please enter a valid input"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> input;
                }
                if(!cin.fail()){
                    break;
                }
            }  
            if (input == 1) {
                switch(option) {
                    case 1:
                        events.setName(name, eventNum);
                    break;
                    case 2:
                        events.setDesc(desc, eventNum);
                    break;
                    case 3:
                        // Will get memory leak here because previous date was not deleted
                        events.setDate(date, eventNum);
                    break;
                    case 4:
                        events.setTime(time, eventNum);
                    break;
                    case 5:
                        events.setlocation(location, eventNum);
                    break;
                }
            }
            cout << endl;
            cout << "Would you like to change anything else?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> input;
            //Input Validation
            while(true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Please enter a numeric input"<<endl;
                    cin >> input;
                }
                if(input != 1 && input != 2){
                    cout<<"Please enter a valid input"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin >> input;
                }
                if(!cin.fail()){
                    break;
                }
            }   
            if (input == 2) {
                return 0;
            }
        }
    }

    ////////////////////////////////
    // EDITING TASKS WITHIN A GOAL
    ////////////////////////////////

    if (goals.getSize() == 0) {
        cout << "You have no goals" << endl;
        cout << "Press any key to return to main menu" << endl;
        int in;
        cin >> in;
        return 0;
    }

    int idGoal;
    int idTask;
    cout << "Enter the Id of goal:" << endl;

    bool isValid = false;

    while (!isValid) {
        cin >> idGoal;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a valid ID"<<endl;
                cin >> idGoal;
            }
            if(!cin.fail()){
                break;
            }
        }        
        if (goals.idExists(idGoal)) {
            isValid = true;
        } else {
            cout << "Invalid Goal ID, try again" << endl;
        }
    }

    // The user has no tasks in the goal
    if (goals.getTasksSize(idGoal) == 0) {
        cout << "You have no tasks within this goal" << endl;
        cout << "Press any key to return to main menu" << endl;
        int in;
        cin >> in;
        return 0;
    }

    cout << "Enter the Id of Task to be deleted:" << endl; 

    isValid = false;

    while (!isValid) {
        cin >> idTask;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a valid ID"<<endl;
                cin >> idTask;
            }
            if(!cin.fail()){
                break;
            }
        }
        if (goals.taskIDExists(idTask, idGoal) ) { 
            isValid = true;
        } else {
            cout << "Invalid Task ID, try again" << endl;
        }
    }

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
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

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
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
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
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }   
        if (input != 1) {
            return 0;
        }
    }

    return 0;
}


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// DELETE TASK MENU
// Can delete tasks that are either in or outside a goal
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int deleteTaskMenu(GoalList& goals, EventList &events) { //Input Validated
    system("clear");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    viewFormatting(goals, events);

    int choice;
    cout << endl;
    cout << "Would you like to delete a task in a goal?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;

    //Input Validation
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter a numeric input"<<endl;
            cin >> choice;
        }
        if(choice != 1 && choice != 2){
            cout<<"Please enter a valid input"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> choice;
        }
        if(!cin.fail()){
            break;
        }
    }
    
    if (choice == 2) {

        if (events.getSize() == 0) {
            cout << "You have no tasks outside goals" << endl;
            cout << "2. Return to main menu" << endl;
            int in;
            cin >> in;
            return 0;
        }

        string name;
        bool foundEvent = false;
        cout << "Enter the name of the task" << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while(!foundEvent) {
            getline(cin, name);

            if (events.findEvent(name)) {
                foundEvent = true;
            } else {
                cout << "Invalid name, please try again" << endl;
            }
        }
        
        int input;
        cout << "1. Confirm delete" << endl;
        cout << "2. Cancel" << endl;
        cin >> input;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
        if (input == 1) {
            events.removeEvent(name);
        }
        return 0;
    } 

        if (goals.getSize() == 0) {
            cout << "You have no goals" << endl;
            cout << "2. Return to main menu" << endl;
            int in;
            cin >> in;
            return 0;
        }

        int idGoal;
        int idTask;
        cout << "Enter the Id of goal:" << endl;

        bool isValid = false;

        while (!isValid) {
            cin >> idGoal;
            //Input Validation
            while(true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Please enter a valid ID"<<endl;
                    cin >> idGoal;
                }
                if(!cin.fail()){
                    break;
                }
            }
            if (goals.idExists(idGoal)) {
                isValid = true;
            } else {
                cout << "Invalid Goal ID, try again" << endl;
            }
        }

        if (goals.getTasksSize(idGoal) == 0) {
            cout << "You have no tasks within this goal" << endl;
            cout << "2. Return to main menu" << endl;
            int in;
            cin >> in;
            return 0;
        }

        cout << "Enter the Id of Task to be edited:" << endl; 

        isValid = false;

        while (!isValid) {
            cin >> idTask;
            //Input Validation
            while(true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Please enter a valid ID"<<endl;
                    cin >> idTask;
                }
                if(!cin.fail()){
                    break;
                }
            }
            if (goals.taskIDExists(idTask, idGoal) ) { 
                isValid = true;
            } else {
                cout << "Invalid Task ID, try again" << endl;
            }
        }

        cout << "1. Confirm delete" << endl;
        cout << "2. Cancel" << endl;
        int input;
        cin >> input;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
        if(1 == input) {
            goals.removeEvent(idGoal, idTask);
        }
        return 0;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// VIEW SCHEDULE
// Can view all the tasks and goals you have
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int viewSchedule(GoalList& goals, EventList &events) { //Input Validated
    system("clear");
    cout << "View Schedule." << endl;
    viewFormatting(goals, events);
    cout << "Press any key to return to menu" << endl;

    int input;
    cin >> input;

    return 0;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// CREATE GOAL MENU
// Can create a goal
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////




int createGoal(GoalList& goals) { //Input Validated
    system("clear");
    cout << "Create Goal Menu." << endl;

    string name;
    string des;
    string date;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
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

    //Input Validation
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter a numeric input"<<endl;
            cin >> input;
        }
        if(input != 1 && input != 2){
            cout<<"Please enter a valid input"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> input;
        }
        if(!cin.fail()){
            break;
        }
    }
    if(1 == input) {
        //save the goal.
        Goal *goal = new Goal(name, des, date);
        goals.addGoal(*goal);
    }
    return 0;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// EDIT GOAL MENU
// Can edit goals
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int editGoal(GoalList& goals) { //Input Validated
    system("clear");
    cout << "Edit Goal Menu." << endl;

    // Check if there are no goals
    if (goals.getSize() == 0) {
        cout << "You have no goals" << endl;
        cout << "Press any key to return to main menu" << endl;
        int in;
        cin >> in;
        return 0;
    }


    cout << "Current goals:" << endl;
    goals.print();
    cout << "*********************************" << endl;
    cout << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    int id;
    string name;
    string des;
    string date;
    cout << "Enter the Id of Goal to edit:" << endl;
    
    bool isValid = false;

    // Until user enters valoid goal ID
    while (!isValid) {
        cin >> id;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> id;
            }
            if(!cin.fail()){
                break;
            }
        }
        if (goals.idExists(id)) {
            isValid = true;
        } else {
            cout << "Invalid Goal ID, try again" << endl;
        }
    }
    
    while(true) {
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << endl;
        cout << "What would you like to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Description" << endl;
        cout << "3. Date" << endl;
        int option;
        cin >> option;
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numerical input"<<endl;
                cin >> option;
            }
            if(option != 1 && option != 2 && option != 3){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> option;
            }
            if(!cin.fail()){
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numerical input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
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
        //Input Validation
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numerical input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
        if (input == 2) {
            return 0;
        }
    }
    return 0;
}


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// DELETE TASK MENU
// Can delete goals
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////



int deleteGoal(GoalList& goals) { //Input Validated
    system("clear");
    cout << "Delete Goal Menu." << endl;
    
    // If there are no goals
    if (goals.getSize() == 0) {
        cout << "You have no goals" << endl;
        cout << "2. Return to main menu" << endl;
        int in;
        cin >> in;
        return 0;
    }

    cout << "Current goals:" << endl;
    goals.print();
    cout << "*********************************" << endl;
    cout << endl;

    int id;
    cout << "Enter the Id of Goal to delete:" << endl;
    
    bool isValid = false;

    // Until the user enters a valid goal ID
    while (!isValid) {
        cin >> id;
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a valid ID"<<endl;
                cin >> id;
            }
            if(!cin.fail()){
                break;
            }
        }
        if (goals.idExists(id)) {
            isValid = true;
        } else {
            cout << "Invalid Goal ID, try again" << endl;
        }
    }

    cout << "1. Confirm delete" << endl;
    cout << "2. Cancel" << endl;
    int input;
    cin >> input;
    //Input Validation
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter a numerical input"<<endl;
            cin >> input;
        }
        if(input != 1 && input != 2){
            cout<<"Please enter a valid input"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> input;
        }
        if(!cin.fail()){
            break;
        }
    }
    if (1 == input) {
        goals.removeGoal(id);
    }
    return 0;
}


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// SHOW MAIN MENU
// Allows the user to navigate through the menu
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int showMainMenu() { //Input Validated

    EventList events;
    GoalList goals;

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
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Please enter a numeric input"<<endl;
                cin >> input;
            }
            if(input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7 && input != 8){
                cout<<"Please enter a valid input"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> input;
            }
            if(!cin.fail()){
                break;
            }
        }
        
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
                viewSchedule(goals, events);
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



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// FORMATTING HELPER FUNCTION 
// Formats the goals and tasks for the user to see
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////



void viewFormatting(GoalList &goals, EventList &events) {

    if (goals.getSize() == 0 && events.getSize() == 0) {
        cout << "No scheduled events or goals" << endl;
    }

    goals.print();
    cout << "*********************************" << endl;


    if (events.getSize() != 0) {
         cout << "Tasks not with a goal:";
    }
    events.displayList();
    cout << endl;
}