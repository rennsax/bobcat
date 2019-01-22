#include "datetime.ih"

    // supported formats:
    //
    //    1: Mon Dec 3 13:29:11 2018
    //    2: Mon Dec 3 13:29:11 CET 2018
    //    3: Mon, 3 Dec 2018 13:29:11 +0100
    //    4: 2018-12-03 13:29:11+01:00

DateTime::Parse::Parse(istream &in, DateTime *ptr)
try
:
    d_in(in),
    d_dt(*ptr)
{
    if (in >> d_dt.d_tm.tm_year)
        fromYear();                 // for 4: 2018-12-03 13:29:11+01:00
    else
        fromDayName();              // for 1..3

    d_dt.d_tm.tm_year -= 1900;
    d_dt.d_tm.tm_isdst = 0;
}
catch (...)
{
    timeException();         // doesn't return, but throws.
}
