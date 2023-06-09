[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10966041&assignment_repo_type=AssignmentRepo)
# Task Scheduler
 
> Authors: [Pranay Singh Thakur](https://github.com/pranay5432), [James Chang](https://github.com/JamesChang039), and [Varun Saraf](https://github.com/varun1724)

## Project Description
Technologies:
 Our group plans to use C++ as our main language as C++ is incredibly responsive and in the long term is incredibly efficient. 
To check for memory leaks, we will be using Valgrind and GDB to debug. 
Our IDE is Visual Studio code and we are working together on the UCR computer science servers.
GitHub will be used for distributed version control and our scrum diagrams will be done using GitHub MoqUps/LucidChart. 
The Googletest submodule and structure will be used for unit tests.
CMake would be used to compile our C++ code into an executable.
Git would be used to allow us to make changes and keep track of stuff locally for our repository.

Description:
Each of us feel as if we have always had a problem with our productivity. To provide ourselves with a tool to fix this, we created a taskscheduler that would allow us to separate our tasks into smaller, more focused goals and tasks in order to keep busy throughout the day and get our things don on time. Our program allows users to add overarching goals that they have for themselves to a schedule and assign individual tasks within these goals. This way, once all the tasks are complete, they will have reached their goal in a productive and healthy manner. The user can also add tasks that are not associated with any individual goal, as we often hav to do tasks throughout the day that are not specific to some overaching theme. Some additional features include editing and deleting goals and tasks and viewing a whole schedule in a neat and easy-to-read display. The project is done using the command line and keyboard, so users can enter in all the information they want with (literally) zero clicks.

Projects Inputs/Outputs:

Inputs:
Users use the keyboard and numbers to create goals and tasks. They can navigate through the main menu by typing in the numbers that are associated with each menu item and pressing enter.

Outputs:
The outputs are the results of what the user enters into the program. If they save any goals/tasks, they will be able to see them in the view schedule option. If they do not have any events, then they will be told so.

## User Interface Specification


### Navigation Diagram
![Navagation Diagram](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/111487418/0b0005b3-9afd-4dcc-83c8-4a874ad4aeef)
TODO - FIX NATIVATION DIAGRAM
The user is greeted with a menu upon running the program. They are prompted to enter certain inputs to access 7 different functions: Create Task, Create Goal, Edit Task, Edit Goal, Delete Task, Delete Goal, and View Schedule. Once they have walked through a function, they will be prompted with the option to return to the main menu.


### Screen Layouts
![Menu](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/17ef736e-4c29-45ac-a013-6ddffcb3c073)

This screen displays the main menu for the user to see. It shows the 8 options that the user has, and the user can navigate through by pressing the number associated with the option and pressing enter. If they select 8, the program will exit. Otherwise, if the input is 1-7, the respective function will be entered into.

![Create Goal/Task](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/1279ab38-358a-49cb-9ff9-2489a9c3d28b)

This screen displays the current goal or task that is being created. In the picture above, it is the goal that is being created but the create tasks menu is very similar. Users are prompted with questions about the event they want to create and it is assigned to their schedule once saved.

![Edit Goal/Task](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/8d3fe2ff-9f3a-4347-a1c2-1d6bd8aef284)

This screen gives the user the option to edit goals or tasks. In the image above, the user has the option to edit a goal that they created, changing its time, name, or desription. Once saved, the changes are applied to the schedule. If the user does not have any goals or tasks they will be told and given the option to return to the main menu.

![Delete Goal/ Task](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/5951cec4-6775-4866-bf00-0fb04e6eea44)

This screen allows the user to delete their goals or tasks. In the image above, the option to delete a goal is shown. Users are presented with information on all of their goals or tasks and their IDs. When selecting a goal to delete, the user enters in the goal's correspoinding ID number and confirms the delete to save. 


### Class Diagram

![umlclassdiagram](https://user-images.githubusercontent.com/103800231/236993307-6cf53752-905b-4580-b8d6-6b1def90e44c.png)

TODO - EDIT CLASS DIAGRAM AND DESCRIPTION. MENTION SOLID PRINCIPLES THAT WERE USED

Above is the OMT class Diagram for the Task Scheduler. The Program functions by providing the user with a basic user interface that shows a calendar. The TaskScheduler class is composed of a Calendar object and a Scheduler object. When the startTaskManager() function is called from main, a case begins to handle the UI of the program and call the functions in both the Calendar and Scheduler classes to be able to display a calendar and allow for it to function. The Design for the program's menus and directories can be found in the user interface above. The task scheduler uses the Singleton design pattern to ensure that only one instance of a task management is created at a time so that the Task Manager can instatiate only one Task Management window at a time. The Task Manager class also contains a ClearScreen() object to be able to close out of the Task Manager.

The storage class helps the Task Manager to store the tasks persistently to a file or a database (we haven't decided yet). The db class interfaces with the file or database. This allows the project to potentially scale if we wanted to in the future, and we can use a variety of storage methods.

The calendar class displays the tasks on a daily basis, it in turn uses the Day class which is made up of a number of tasks in that specific day. In the day class we can add tasks, delete tasks, and edit tasks.

The interaction of the classes is like this:

When the application starts it loads the task data using the storage class which in turn receives stored user data from the db class, then the task data is populated in the calendar and displayed. When the user clicks on a particular day, they would see the task in that specific day. Through clicking the day, the user would be able to add, delete, and edit the task. The task manager also uses the scheduler which in turn uses the task data to prioritize the tasks as per the priority given by the user. The user would be able to edit the tasks and increase or decrease the priority. A task can also be made up of subtasks.


 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.

 
 > ## Final deliverable
 TODO - IN PROGRESS AND IN TESTING COLUMNS NEED TO BE EMPTY. TODO COLUMN SHOULD INCLUDE ANY KNOWN BUGS OR FEATURES WE WOULD LIKE TO INCLUDE
 
 ## Screenshots
 ![Viewing an empty schedule](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/695bdaee-de03-4532-9fe0-ef3f39af1f21)
 
  ![Viewing a busy schedule](https://github.com/cs100/final-project-pthak008-jchan517-2/assets/112217896/89bd0d3a-d5d5-4594-847d-203ad8833143)
 
 ## Installation/Usage

Begin by cloning this github to your local device in a folder. This can be done by navigating to your desired location using the terminal command "cd" and running git clone "https://github.com/cs100/final-project-pthak008-jchan517-2". Any major IDE will work to run the program, so once you have the IDE open, open the project by navigating to the folder in which you cloned it. Open the terminal once again (it does not necessarily need to be an integrated terminal in your IDE) and run the command "cmake ." and hit enter. Next, run the command "make". Finally, your exectuable will be created and you can go ahead and run "bin/taskscheduler" to run the program.


 ## Testing
 TODO - THIS SECTION
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
