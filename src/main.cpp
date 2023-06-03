#include <iostream>

#include "../headers/Calendar.h"

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
        }
    }
    return 0;
}
int editTaskMenu() {
    system("clear");
    cout << "Edit Task Menu." << endl;
    cout << "2. Back" << endl;
    int input;
    cin >> input;
    return 0;
}
int deleteTaskMenu() {
    system("clear");
    cout << "Delete Task Menu." << endl;
    cout << "2. Back" << endl;
    int input;
    cin >> input;
    return 0;
}
int viewSchedule() {
    system("clear");
    cout << "View Schedule." << endl;
    cout << "2. Back" << endl;
    int input;
    cin >> input;
    return 0;
}

int showMainMenu() {

    EventList events = EventList();

    while(true) {
        system("clear");
        cout <<"Main Menu"<<endl;
        cout <<"Select option"<<endl;
        cout <<"1. Create Task"<<endl;
        cout <<"2. Edit Task"<<endl;
        cout <<"3. Delete Task"<<endl;
        cout <<"4. View Schedule"<<endl;
        cout <<"5. Exit"<<endl;
        
        int input;
        cin >> input;
        switch (input){
            case 1:
            //Show create task menu.
            showCreateTaskMenu(events);
            break;

            case 2:
            //Edit task menu.
            editTaskMenu();
            break;

            case 3:
            //Show delete task menu.
            deleteTaskMenu();
            break;

            case 4:
            //View schedule.
            viewSchedule();
            break;

            case 5:

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



