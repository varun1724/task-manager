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

# > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
![Navagation Diagram](https://user-images.githubusercontent.com/111487418/236964289-99dc8ef3-c7df-4871-867f-4f7e66d85874.png) The user is able to navegate between the month and day screens by either clicking on the individual dates or the back button on the date screen. From both the day and month screen, the user is able to access the goals screen by clicking on the goals text on the side of the calendar. The user is able to turn back to either to day or month screen from the goals screen by pressing the back button. From the day, month and goals screen, users are able to add new events/goals by clicking the respective buttons, and are also able to turn by either clicking the confirm button or the cancel button to return without adding anything.


### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.


### Class Diagram

![Class Diagram](https://github.com/cs100/final-project-pthak008-jchan517-2/blob/master/umlclassdiagram.png)
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
 
