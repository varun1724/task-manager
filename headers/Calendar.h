#include <Month.h>
using namespace std;


class Calendar
{
private:
    Month* month;
    int year;
public:
    Calendar(int, string);
    ~Calendar();
};

Calendar::Calendar(int year, string month)
{
    month = new Month(month, year);
    this->year = year;
}

Calendar::~Calendar()
{
}
