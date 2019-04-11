#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

void show(DateTime const &dt, char const *label)
{
    cout << 
        label << ": " << dt << "\n"
//        "dst: " << (dt.dst() == DateTime::YES) << "\n"
        "hh:mm:ss: " << dt.hours() << ':' << dt.minutes() << ':' << 
                        dt.seconds() << "\n"
        "year-month-monthdaynr: " << dt.year() << '-' << dt.month() << '-' <<
                                     dt.monthDayNr() << "\n"
        "weekday/weeknr/yearday/yeardaynr: " << 
//            dt.weekday() << '/' << dt.weekNr() << '/' << 
            dt.yearDay() << '/' << dt.yearDayNr() << "\n"
        "\n";
}

int main()
{
    time_t now = time(0);

    DateTime utc{ now, DateTime::UTC };
    cout << "UTC: " << utc << '\n';

    utc += tm{ 0, 0, 2, 1 };
    cout << utc << '\n';

cout << "\n\n";


    DateTime dt{ now, DateTime::LOCALTIME };
    cout << "Local time: " << dt << '\n';

    dt += tm{ 0, 0, 2, 1 };
    cout << dt << '\n';

    dt += chrono::hours(1);
    cout << dt << '\n';

//
//    utc.setFields(
//                    tm{ 0, 0, 8, 1 }, 
//                    DateTime::SECONDS | 
//                    DateTime::HOURS | 
//                    DateTime::MONTHDAY
//                );
//    show(utc, "utc, 1st, 8 hrs, zero seconds");
//
//    cout << "---------------\n";
//
//    DateTime dt{ now, DateTime::LOCALTIME };
//    cout << "Local time: " << dt << '\n';
//
//    dt.setFields(
//                    tm{ 0, 0, 8, 1 }, 
//                    DateTime::SECONDS | 
//                    DateTime::HOURS | 
//                    DateTime::MONTHDAY
//                );
//    show(dt, "local time, 1st, 8 hrs, zero seconds");
//
//    DateTime dt2{ now, DateTime::LOCALTIME };
//    dt2.setDay(dt2.monthDayNr() - 7);
//    show(dt2, "local time, one week ago");
//
}



