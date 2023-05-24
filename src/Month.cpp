#include "../headers/Month.h"

// Switches the current month to the next month and increases the year if necessary
void Month::nextMonth() const {

    if (monthName == "January") {
        monthName = "February";
    } else if (monthName == "February") {
        monthName = "March";
    } else if (monthName == "March") {
        monthName = "April";
    } else if (monthName == "April") {
        monthName = "May";
    } else if (monthName == "May") {
        monthName = "June";
    } else if (monthName == "June") {
        monthName = "July";
    } else if (monthName == "July") {
        monthName = "August";
    } else if (monthName == "August") {
        monthName = "September";
    } else if (monthName == "September") {
        monthName = "October";
    } else if (monthName == "October") {
        monthName = "November";
    } else if (monthName == "November") {
        monthName = "December";
    } else if (monthName == "December") {
        monthName = "January";
        year += 1;
    } 
}

// Switches the current month to the previous month and decreases the year if necessary
void Month::nextMonth() const {

    if (monthName == "January") {
        monthName = "December";
        year -= 1;
    } else if (monthName == "February") {
        monthName = "January";
    } else if (monthName == "March") {
        monthName = "February";
    } else if (monthName == "April") {
        monthName = "March";
    } else if (monthName == "May") {
        monthName = "April";
    } else if (monthName == "June") {
        monthName = "May";
    } else if (monthName == "July") {
        monthName = "June";
    } else if (monthName == "August") {
        monthName = "July";
    } else if (monthName == "September") {
        monthName = "August";
    } else if (monthName == "October") {
        monthName = "September";
    } else if (monthName == "November") {
        monthName = "October";
    } else if (monthName == "December") {
        monthName = "November";
    } 
}

// Helper function that returns the amount of days in the current month
int Month::numDays() const {
    if (monthName == "April" || monthName == "June" || monthName == "September" || monthName == "November") {
        return 30;
    } else if (monthName == "February") {
        if (isLeapYear()) {
            return 29;
        }
        return 28;
    }

    return 31;
}

// Helper function that determines if the year is a leap year
bool Month::isLeapYear() const {
    
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }

    return false;
}