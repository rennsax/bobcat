#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

void show(DateTime const &dt, char const *label)
{
    cout << 
        label << ": " << dt << "\n"
        "dst: " << (dt.dst() == DateTime::YES) << "\n"
        "hh:mm:ss: " << dt.hours() << ':' << dt.minutes() << ':' << 
                        dt.seconds() << "\n"
        "year-month-monthdaynr: " << dt.year() << '-' << dt.month() << '-' <<
                                     dt.monthDayNr() << "\n"
        "weekday/weeknr/yearday/yeardaynr: " << 
            dt.weekday() << '/' << dt.weekNr() << '/' << 
            dt.yearDay() << '/' << dt.yearDayNr() << "\n"
        "\n";
}

int main()
{
    time_t now = time(0);

    DateTime utc{ now, DateTime::UTC };
    show(utc, "UTC");

    DateTime local{ utc.thisTime() };

    cout << "the computer's local time: " << local << '\n';

    DateTime dt{ now, DateTime::LOCALTIME };
    show(dt, "Local time");

    DateTime utc2{ dt.utc() };
    cout << "utc from local time: " << utc2 << '\n';

    DateTime jan1{ "2019-01-01 13:29:11+01:00", DateTime::LOCALTIME };
    cout << "Jan 1: " << jan1 << '\n';
    show(jan1, "January 1st");
}


