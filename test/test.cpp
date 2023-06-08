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
