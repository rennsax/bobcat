#include "main.ih"

void changeHours()
{
    if (not setHours)
        return;

    time_t current = time(0) + desiredZone + desiredDST;

    tm ts;

    gmtime_r(&current, &ts);            // get the desired time spec. in ts.


    ts.tm_sec -= localDST;              // correction for local DST
    ts.tm_hour = hours;                 // set the new hours value

    mktime(&ts);                        // update ts

    showTM(ts, "Changed hours");
}

