#include <iostream>

#include "../headers/Calendar.h"

using namespace std;



int showCreateTaskMenu() {
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
            cin >> input;
        } else if(input == 2) {
            return 0;
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
            showCreateTaskMenu();
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

    Calendar cal = Calendar(2023, "May");
    cal.printCalendar();

    //int ret = showMainMenu();
    return 0;
}



