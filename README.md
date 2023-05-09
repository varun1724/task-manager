[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10966041&assignment_repo_type=AssignmentRepo)
# Task Scheduler
 
> Authors: [Pranay Singh Thakur](https://github.com/pranay5432), [James Chang](https://github.com/JamesChang039), and [Varun Saraf](https://github.com/varun1724)

## Project Description
Technologies:
 Our group plans to use C++ as our main language as C++ is incredibly responsive and in the long term is incredibly efficient. 
Due to us using C++, we would have to use Valgrind to check for memory leaks.
GDB for debugging. 
Visual Studio Code as our IDE and to be able to connect to UCR's servers.
GitHub for distributed version control. 
For Scrum we are using GitHub MoqUps/LucidChart for diagrams. 
The GTest structure for unit tests. 
Vim would be used for quick edits for files such as CMakeLists.txt
CMake would be used to compile our C++ code into an executable.
Git would be used to allow us to make changes and keep track of stuff locally for our repository.

Description:
The members of my group and I want to become more productive and being able to make a high quality, responsive, task scheduler would help a large amount to reach our goals. Being able to be productive has always been a problem, and having a task scheduler would at the very least help us prioritize the tasks most important to us. Prioritizing constantly scheduling tasks would slowly help our group members to reach our personal productivity goals and to complete more tasks/goals. A good example of a task/goal for both of our group members is to increase/maintain the amount of good grades that we have in school. To achieve these longterm goals for us in this project, the project needs a complex featureset that can help to reach these goals. The features would be an internal calendar that enables the insertion and retrieval of tasks with their dates and times. Users of this project can schedule events and tasks infinitely far in the future, enabling each user to be able to reach specific goals and targets incrementally using these tasks. Also, users can assign these specific tasks for specific goals, so if the user has a specific goal they can assign a large amount of tasks to be able to achieve this goal. The task scheduler would also help users to be individually be able to time manage specific tasks, since presets can be added for each day so if the user has recurring events, timeslots can be blocked in case a task conflicts (this can be overriden in certain scenarios but it would prevent the user from overcommitting). Also, the user can check the amount of hours the combination of tasks would take as a way to prevent overcommitting in the longterm. The task scheduler would be able to suggest times through remembering some of the users most done tasks combined with looking at existing tasks and reserved blocks that are scheduled. This project's goal is to be the ultimate task scheduler so that our group would be able to schedule tasks in the long run.

Projects Inputs/Outputs:

Inputs:
Users would able to input their existing schedules and recurring tasks. New tasks and their specific times/dates. They can also input their long term goals to match specific tasks to.

Outputs:
Users can retrieve thier specific tasks/goals. They can also retrieve the progression for these tasks/goals. Tehy can also retrieve the times/dates/scheduled time of teach task.
## User Interface Specification


### Navigation Diagram
![Navagation Diagram](https://user-images.githubusercontent.com/111487418/236964289-99dc8ef3-c7df-4871-867f-4f7e66d85874.png)

The user is able to navigate between the month and day screens by either clicking on the individual dates or the back button on the date screen. From both the day and month screen, the user is able to access the goals screen by clicking on the goals text on the side of the calendar. The user is able to turn back to either to day or month screen from the goals screen by pressing the back button. From the day, month and goals screen, users are able to add new events/goals by clicking the respective buttons, and are also able to turn by either clicking the confirm button or the cancel button to return without adding anything.


### Screen Layouts
![Month Page](https://user-images.githubusercontent.com/112217896/236991391-739dc74a-b681-4a29-877e-2057d6b0f418.jpg)

This screen displays the main calendar along with the names of the tasks that the user has assigned for themselves. On the right a section is displayed for the goals that the user has assigned themselves for the month. The top section displays two buttons that when clicked can be used to add new events or goals. Each individual goal can also be clicked into, bringing the screen to a new screen that displays any tasks assigned to the specific goal. Next to the goals, the set of arrows will change the month forwards and backwards. If a specific date is clicked, then the screen changes to the day screen, as described next.

![Day Screen](https://user-images.githubusercontent.com/112217896/236991446-8e49cd81-a10c-4bb7-8af1-b619bf2ad6fe.jpg)

This screen displays an individual day along with the events that a user has planned. It shows the events next to the time that they have been planned for, along with a description under their title. If the user clicks on a goal, they will have the option to edit or delete it. On the right, the same goal screen as the month page is shown with the same functionality. The top also displays the same new event and goal buttons as the month page. The forward and backwards arrows can be used to change days, and the back button at the top left will navigate back to the month screen.

![Individual Goal Screen](https://user-images.githubusercontent.com/112217896/236991431-1f34215f-4452-400a-9179-ca79f2414ac4.jpg)

This screen displays an individual goal and the specific tasks assigned to the goal. Users have the option to edit, delete, or add new tasks to the goal. They can also add a new goal, as the goal screen from before remains unchanged. The arrows will bring the user to the next or previous goal, and the back arrow at the top left will bring the user back to the day screen. 

![Add event pop-up screen](https://user-images.githubusercontent.com/112217896/236991470-292dfc35-43b3-4646-9fb4-fb0a8b636b11.jpg)

This screen is a pop up that shows if the user clicks the button to add a new event or task. It prompts the user for information about the event/task they are going to add and has two buttons to confirm or cancel this addition


### Class Diagram

![umlclassdiagram](https://user-images.githubusercontent.com/103800231/236993307-6cf53752-905b-4580-b8d6-6b1def90e44c.png)

Above is the OMT class Diagram for the Task Scheduler. The Program functions by providing the user with a basic user interface that shows a calendar. The TaskScheduler class is composed of a Calendar object and a Scheduler object. When the startTaskManager() function is called from main, a case begins to handle the UI of the program and call the functions in both the Calendar and Scheduler classes to be able to display a calendar and allow for it to function. The Design for the program's menus and directories can be found in the user interface above. The task scheduler uses the Singleton design pattern to ensure that only one instance of a task management is created at a time so that the Task Manager can instatiate only one Task Management window at a time. The Task Manager class also contains a ClearScreen() object to be able to close out of the Task Manager.

The storage class helps the Task Manager to store the tasks persistently to a file or a database (we haven't decided yet). The db class interfaces with the file or database. This allows the project to potentially scale if we wanted to in the future, and we can use a variety of storage methods.

The calendar class displays the tasks on a daily basis, it in turn uses the Day class which is made up of a number of tasks in that specific day. In the day class we can add tasks, delete tasks, and edit tasks.

The interaction of the classes is like this:

When the application starts it loads the task data using the storage class which in turn receives stored user data from the db class, then the task data is populated in the calendar and displayed. When the user clicks on a particular day, they would see the task in that specific day. Through clicking the day, the user would be able to add, delete, and edit the task. The task manager also uses the scheduler which in turn uses the task data to prioritize the tasks as per the priority given by the user. The user would be able to edit the tasks and increase or decrease the priority. A task can also be made up of subtasks.


 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
