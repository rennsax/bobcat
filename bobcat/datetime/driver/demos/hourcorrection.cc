#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    time_t current = time(0);               // current (any utc-like time
                                            //          since the epoch)

    struct tm *ts;

    ts = localtime(&current);               // convert to struct tm
    bool dst = ts->tm_isdst == 1;           // the computer thinks DST is used

    ts = gmtime(&current);                  // compute UTC broken-down time
                                            // specification

    cout << "UTC hours: " << ts->tm_hour << '\n';   // UTC hours

    ts->tm_hour = 17 + dst;                 // set hours to 17
    time_t time2 = mktime(ts);              // convert to seconds
    ts = gmtime(&time2);                    // broken-down time specification
    cout << "hours when hr set to 17: " << ts->tm_hour << "\n\n";   

    // now assume the time zone shift is +4 hrs wrt UTC
    
    time_t zoneTime;
    zoneTime = current + 4 * 3600;
    ts = gmtime(&zoneTime);
    cout << "zone (+4 hr) hours: " << ts->tm_hour << '\n'; 


    // determine the local time (CET = 1 hr):
    zoneTime = current + 3600 + dst * 3600;
    ts = gmtime(&zoneTime);
    cout << "local hours: " << ts->tm_hour << '\n'; 


    // set the local time to noon (12 hrs)
    zoneTime = current + 3600 + dst * 3600;
    ts = gmtime(&zoneTime);
    ts->tm_hour = 12 + dst;
    zoneTime = mktime(ts);
    ts = gmtime(&zoneTime);
    cout << "noon: " << ts->tm_hour << '\n'; 
}
