#include "googletest/googletest/include/gtest/gtest.h"
#include "../headers/Goal.h"
#include "../headers/GoalList.h"

using namespace std;

TEST(GoalTests, testGoalGetName) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    EXPECT_EQ (goal->getName(), name);
}

TEST(GoalTests, testGoalGetdes) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    EXPECT_EQ (goal->getDescription(), des);
}

TEST(GoalTests, testGoalGetDate) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    EXPECT_EQ (goal->getDate(), date);
}

TEST(GoalTests, testGoalSetName) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    string newName = "newgoal1";
    goal->setName(newName);
    EXPECT_EQ (goal->getName(), newName);
}

TEST(GoalTests, testGoalSetDes) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    string newDescription = "new description";
    goal->setDescription(newDescription);
    EXPECT_EQ (goal->getDescription(), newDescription);
}

TEST(GoalTests, testGoalSetDate) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    string newDate = "06/24/2023";
    goal->setDate(newDate);
    EXPECT_EQ (goal->getDate(), newDate);
}

TEST(GoalListTests, testGoalListSize) {
    GoalList* goalList = new GoalList();
    EXPECT_EQ (goalList->getSize(), 0);
}

TEST(GoalListTests, testGoalListAdd) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    EXPECT_EQ (goalList->getSize(), 1);
}

TEST(GoalListTests, testGoalListRemove) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    goalList->removeGoal(1);
    EXPECT_EQ (goalList->getSize(), 0);
}

TEST(GoalListTests, testGoalListAddEvent) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    EXPECT_EQ (goalList->idExists(1), true);
}

TEST(GoalListTests, testGoalListRemoveEvent) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    goalList->removeEvent(1, 0);
    
    EXPECT_EQ (goalList->taskIDExists(1,0), false);
}

TEST(GoalListTests, testGoalListSetGoalName) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    string newName = "newgoal1";
    goalList->setGoalName(1, newName);
    Goal& goal1 = goalList->getGoal(1);
    EXPECT_EQ (goal1.getName(), newName);
}

TEST(GoalListTests, testGoalListSetGoalDes) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    string newDes = "newdes";
    goalList->setGoalDescription(1, newDes);
    Goal& goal1 = goalList->getGoal(1);
    EXPECT_EQ (goal1.getDescription(), newDes);
}

TEST(GoalListTests, testGoalListSetGoalDate) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    string newDate = "06/14/2023";
    goalList->setGoalDate(1, newDate);
    Goal& goal1 = goalList->getGoal(1);
    EXPECT_EQ (goal1.getDate(), newDate);
}

TEST(GoalListTests, testGoalListSetTaskName) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    string newName = "newTaskName";
    goalList->setTaskName(1, 0, newName);
    Event& event1 = goalList->getEvent(1, 0);
    
    EXPECT_EQ (event1.getName(), newName);
}

TEST(GoalListTests, testGoalListSetTaskDes) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    string newDes = "newDes";
    goalList->setTaskDescription(1, 0, newDes);
    Event& event1 = goalList->getEvent(1, 0);
    
    EXPECT_EQ (event1.getDescription(), newDes);
}

TEST(GoalListTests, testGoalListSetTaskDate) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    string newDate = "12/2/2023";
    goalList->setTaskDate(1, 0, newDate);
    Event& event1 = goalList->getEvent(1, 0); 
    EXPECT_EQ (event1.getDate(), newDate);
}

TEST(GoalListTests, testGoalListSetTaskTime) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    string newTime = "11:11";
    goalList->setTaskTime(1, 0, newTime);
    Event& event1 = goalList->getEvent(1, 0); 
    EXPECT_EQ (event1.getTime(), newTime);
}

TEST(GoalListTests, testGoalListSetTaskLocation) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    string newLocation = "newLocation";
    goalList->setTaskLocation(1, 0, newLocation);
    Event& event1 = goalList->getEvent(1, 0); 
    EXPECT_EQ (event1.getLocation(), newLocation);
}

TEST(GoalListTests, testGoalListIdExists) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    EXPECT_EQ (goalList->idExists(1), true);
}

TEST(GoalListTests, testGoalListGetTaskSize) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    EXPECT_EQ (goalList->getTasksSize(1), 1);
}

TEST(GoalListTests, testGoalListPrint) {
    string name = "goal1";
    string des = "This is goal1";
    string date = "06/12/2023";
    Goal *goal = new Goal(name, des, date);
    GoalList* goalList = new GoalList();
    goalList->addGoal(*goal);
    Goal& goal1 = goalList->getGoal(1);
    Event *event = new Event("task1", "description", "12/1/2022", "12:11", "location");
    goalList->addEvent(1, *event);
    testing::internal::CaptureStdout();
    goalList->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE (output, "");
}

TEST(EventTest, testEventGetName) {
    string name = "event1";
    string des = "This is event1";
    string date = "03/30/2023";
    string time = "12:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getName();
    EXPECT_EQ(event->getName(), name);
}

TEST(EventTest, testEventGetEmptyName) {
    Event *event = new Event();
    event->getName();
    EXPECT_EQ(event->getName(), "");
}

TEST(EventTest, testEventGetDescription) {
    string name = "event2";
    string des = "This is event2";
    string date = "01/30/2023";
    string time = "01:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getDescription();
    EXPECT_EQ(event->getDescription(), des);
}

TEST(EventTest, testEventGetDate) {
    string name = "event4";
    string des = "This is event4";
    string date = "11/30/2023";
    string time = "11:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getDate();
    EXPECT_EQ(event->getDate(), date);
}

TEST(EventTest, testEventGetTime) {
    string name = "event3";
    string des = "This is event3";
    string date = "07/30/2023";
    string time = "11:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getTime();
    EXPECT_EQ(event->getTime(), time);
}

TEST(EventTest, testEventGetLocation) {
    string name = "event5";
    string des = "This is event5";
    string date = "07/30/2023";
    string time = "11:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getLocation();
    EXPECT_EQ(event->getLocation(), location);
}

TEST(EventTest, testEventGetGoalStatus) {
    string name = "event6";
    string des = "This is event6";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getGoalStatus();
    EXPECT_EQ(event->getGoalStatus(), false);
}

TEST(EventTest, testEventGetTaskID) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->getTaskID();
    EXPECT_EQ(event->getTaskID(), 0);
}

TEST(EventTest, testEventSetName) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setName("test");
    EXPECT_EQ(event->getName(), "test");
}

TEST(EventTest, testEventSetDescription) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setDescription("");
    EXPECT_EQ(event->getDescription(), "");
}

TEST(EventTest, testEventSetDate) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setDate("test");
    EXPECT_EQ(event->getDate(), "test");
}

TEST(EventTest, testEventSetTime) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setTime("15:00");
    EXPECT_EQ(event->getTime(), "15:00");
}

TEST(EventTest, testEventSetLocation) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setLocation("Test Home");
    EXPECT_EQ(event->getLocation(), "Test Home");
}

TEST(EventTest, testEventSetGoalStatus) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setGoalStatus(true);
    EXPECT_EQ(event->getGoalStatus(),true);
}

TEST(EventTest, testEventSetTaskID) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    event->setTaskID(4);
    EXPECT_EQ(event->getTaskID(), 4);
}

TEST(EventTest, testEventPrintEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    testing::internal::CaptureStdout();
    event->printEvent();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE (output, "");
}

TEST(EventListTest, testAddEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    EXPECT_EQ (testList.getSize(), 1);
}

TEST(EventListTest, testRemoveEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.removeEvent(name);
    EXPECT_EQ (testList.getSize(), 0);
}

TEST(EventListTest, testRemoveEvent2) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event);
    testList.removeEvent(1);
    EXPECT_EQ (testList.getSize(), 1);
}

TEST(EventListTest, testfindEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    EXPECT_EQ (testList.findEvent(name), true);
}

TEST(EventListTest, testfindEvent2) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    EXPECT_EQ (testList.findEvent("fail"), false);
}

TEST(EventListTest, testFindEventNumber) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    EXPECT_EQ (testList.findEventNumber(name), 0);
}

TEST(EventListTest, testDisplayList) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testing::internal::CaptureStdout();
    testList.displayList();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE (output, "");
}

TEST(EventListTest, testDisplayNames) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testing::internal::CaptureStdout();
    testList.displayNames();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE (output, "");
}

TEST(EventListTest, testDisplayEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testing::internal::CaptureStdout();
    testList.displayEvent(name);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE (output, "");
}

TEST(EventListTest, testGetEvent) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getName(), name);
}

TEST(EventListTest, testGetSize) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    EXPECT_EQ (testList.getSize(), 3);
}

TEST(EventListTest, testGetLargestTaskID) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    EXPECT_EQ (testList.getLargestTaskId(), 0);
}

TEST(EventListTest, testtaskIDExist) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    EXPECT_EQ (testList.taskIDExists(4), false);
}

TEST(EventListTest, testSetName) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    string newName = "newName";
    testList.setName(newName, 0);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getName(), newName);
}

TEST(EventListTest, testSetDescription) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    string newDes = "newDes";
    testList.setDesc(newDes, 0);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getDescription(), newDes);
}

TEST(EventListTest, testSetDate) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    string newDate = "11/30/2020";
    testList.setDate(newDate, 0);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getDate(), newDate);
}

TEST(EventListTest, testSetTime) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    string newTime = "11:00";
    testList.setTime(newTime, 0);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getTime(), newTime);
}

TEST(EventListTest, testSetLocation) {
    string name = "event7";
    string des = "This is event7";
    string date = "07/30/2020";
    string time = "14:00";
    string location = "test Location";
    Event *event = new Event(name,des,date,time,location);
    Event *event2 = new Event("test case",des,date,time,location);
    Event *event3 = new Event(name,des,date,time,location);
    EventList testList;
    testList.addEvent(*event);
    testList.addEvent(*event2);
    testList.addEvent(*event3);
    string newLocation = "newLocation";
    testList.setlocation(newLocation, 0);
    Event& event4 = testList.getEvent(0);
    EXPECT_EQ (event4.getLocation(), newLocation);
}
