#include <iostream>
#include <string.h>
#include "../headers/Calendar.h"


void Calendar::printCalendar() {


    cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
    cout << "------------------------------------------" << endl;


}
Calendar::~Calendar(){

}
Calendar::Calendar(int year, string monthName){
    curMonth = new Month(year, monthName);
    this->year = year;
}

