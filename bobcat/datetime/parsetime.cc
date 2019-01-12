#include "datetime.ih"

    // supported formats:
    //
    //    1: Mon Dec 3 13:29:11 2018
    //    2: Mon Dec 3 13:29:11 CET 2018
    //    3: Mon, 3 Dec 2018 13:29:11 +0100
    //    4: 2018-12-03 13:29:11+01:00

DateTime::Parse DateTime::parseTime(string const &timeStr)
try
{
    istringstream in(timeStr);

    Parse parse{ 
            in >> d_tm.tm_year ?
                    parseFromYear(in)   // for 4: 2018-12-03 13:29:11+01:00
                :
                    parseFromDayName(in)    // for 1..3
          };

    d_tm.tm_year -= 1900;
    d_tm.tm_isdst = 0;

    return parse;
}
catch (...)
{
    return timeException(timeStr);      // doesn't return, but throws.
}

