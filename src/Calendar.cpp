#include <iostream>
#include <string.h>
#include "../headers/Calendar.h"


void Calendar::printCalendar() {

    cout << endl;
    cout << "Year: "<<this->getYear()<<" "<<"Month: " << curMonth->getMonthName() << endl;
    cout << endl;
    if(curMonth->numDays() ==  28){
        cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   1     2     3     4     5     6     7" << endl; // 5 spaces in between single digit numbers
        cout << "   8     9    10    11    12    13    14" << endl;
        cout << "  15    16    17    18    19    20    21" << endl;
        cout << "  23    24    25    26    27    28      " << endl;
    }
    else if(curMonth->numDays() ==  29){
        cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   1     2     3     4     5     6     7" << endl; // 5 spaces in between single digit numbers
        cout << "   8     9    10    11    12    13    14" << endl;
        cout << "  15    16    17    18    19    20    21" << endl;
        cout << "  23    24    25    26    27    28    29" << endl;
    }
    else if(curMonth->numDays() ==  30){
        cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   1     2     3     4     5     6     7" << endl; // 5 spaces in between single digit numbers
        cout << "   8     9    10    11    12    13    14" << endl;
        cout << "  15    16    17    18    19    20    21" << endl;
        cout << "  23    24    25    26    27    28    29" << endl;
        cout << "  30                                    " << endl;
    }
    else{
        cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   1     2     3     4     5     6     7" << endl; // 5 spaces in between single digit numbers
        cout << "   8     9    10    11    12    13    14" << endl;
        cout << "  15    16    17    18    19    20    21" << endl;
        cout << "  23    24    25    26    27    28    29" << endl;
        cout << "  30    31                              " << endl;
    }

}
Calendar::~Calendar(){

}
Calendar::Calendar(int year, string monthName){
    curMonth = new Month(year, monthName);
    this->year = year;
}

void Calendar::nextCalMonth(){
    this->curMonth->nextMonth();
}

void Calendar::prevCalMonth(){
    this->curMonth->prevMonth();
}

int Calendar::getYear(){
    return this->year;
}


