#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void show(char const *label, tm const &tmOut)
{
    cout << setw(30) << label << ": " << setfill('0') << 
                setw(2) << tmOut.tm_hour << ':' <<
                setw(2) << tmOut.tm_min << ':' <<
                setw(2) << tmOut.tm_sec << ' ' <<
                setw(4) << (tmOut.tm_year + 1970) << '-' <<
                setw(2) << (tmOut.tm_mon + 1) << '-' <<
                setw(2) << tmOut.tm_mday << setfill(' ') << '\n';
}

int main()
{
    [[maybe_unused]] time_t d_zone = 3600;   // local zone = 1 hour = 3600 sec.
    time_t d_time;


    tm d_tm   // local time representation
    {
        0,                  // sec
        0,                  // min
        12,                 // hour   
        10,                 // mday
        2,                  // mon
        2018 - 1970         // year
    };

    show("pre", d_tm);
    d_time = mktime(&d_tm); // compute utc time_t (11:00)

    // --------------------------------------------------------------------
    // precondition: d_time is available for the currently represented time

    gmtime_r(&d_time, &d_tm);       // specs for UTC now in d_tm

    show("utc representation", d_tm);   // info only

        // update the fields from an external source:
    d_tm.tm_hour += 2;       // add 2 hrs
    d_tm.tm_mon += 4;        // add 4 months

        // add the default zone seconds:
    d_tm.tm_sec += d_zone;   // add local zone

        // compute the new UTC time representation
    d_time = mktime(&d_tm);

        // PM: call refreshTM to update d_tm given the current zone and DST

    // -------------------------------------------------------------------


    time_t local = d_time + d_zone; // new local time to compute new `in'
    gmtime_r(&local, &d_tm);        // new representation not counting DST

    show("+ 4 mon, + 2 hr", d_tm);
}




