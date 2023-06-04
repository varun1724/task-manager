#include <iostream>
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
int deleteTaskMenu() {
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
int viewSchedule() {
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
                createGoal();
            break;

            case 6:
                editGoal();
            break;
            
            case 7:
                deleteGoal();
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
    return 0;
}



