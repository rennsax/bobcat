#include "datetime.ih"

DateTime::Parse DateTime::parseStream(istream &in)
try
{
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
    return timeException();         // doesn't return, but throws.
}
