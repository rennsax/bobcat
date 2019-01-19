#include "datetime.ih"

DateTime::Parse DateTime::parseFromDayName(istream &in)
{
    in.clear();             // not starting with a year

    string day;

    if (not (in >> day))                        // #1-#3 require day
        throw 1;

    return day.back() == ',' ?                  
                parseDateR(in)                  // format #3
            :
                parseFromMonth(in);             // formats #1, #2
}





