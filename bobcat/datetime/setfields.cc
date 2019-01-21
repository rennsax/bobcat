#include "datetime.ih"

bool DateTime::setFields(TM const &ts, TimeFields fields)
{
    TM src;

    gmtime_r(&d_time, &src);

    if (fields & SECONDS)
        src.tm_sec = ts.tm_sec;

    if (fields & MINUTES)
        src.tm_min = ts.tm_min;

    if (fields & HOURS)
        src.tm_hour = ts.tm_hour;

    if (fields & MONTHDAY)
        src.tm_mday = ts.tm_mday;

    if (fields & MONTH)
        src.tm_mon = ts.tm_mon;

    if (fields & YEAR)
        src.tm_year = ts.tm_year - 1900;

    return setTMfields(src, 
        [](TM &dest, TM const &src)
        {
            dest = src;
        }
    );
}








