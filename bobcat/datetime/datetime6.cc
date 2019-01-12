#include "datetime.ih"

// time provodes UTC time, tzShift (in minutes) sets d_zone

DateTime::DateTime(time_t time, int tzShift)    // tzShift in minutes
:
    d_time(time)
{
    iniZoneDst(tzShift);                        // 2.cc
}

