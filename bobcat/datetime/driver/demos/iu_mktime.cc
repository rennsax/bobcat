#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

time_t zoneShift() 
{
    tm ts;
    time_t secs = 0;
    return -mktime(gmtime_r(&secs, &ts));
}

void tout(char const *label, tm const &ts)
{
    cout << setw(25) << label << ":"
        "   hr "   << ts.tm_hour    << 
        ",  mon "  << ts.tm_mon     << 
        ",  day "  << ts.tm_mday     << 
        ",  DST " <<  ts.tm_isdst   << '\n';
}

time_t utcTime(tm *ts, int *dst)
{
    time_t time = mktime(ts);            // mktime returns ts's UTC - zonesecs
    tout("*** tm after mktime", *ts);

    if (ts->tm_isdst <= 0)
        *dst = 0;
    else
    {
        *dst = 3600;
        time -= 3600;
    }

    return time;
}

int main()
{

    tm ts0 =                 // considered UTC time
    {
        0,
        0,
        12,                // hr
        1,                 // daynr
        0,                 // Jan
        118,
    };

    tm ts = ts0;
    int dst = 0;
    time_t localTime;
    time_t zone = zoneShift();

    cout << "   Local time: Jan 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    time_t jan = utcTime(&ts, &dst);   // mktime returns ts's UTC - zonesecs

    gmtime_r(&jan, &ts);
    cout << "Jan.: " << jan << ": " <<  // + dst shift
            put_time(&ts, "%c") << 
            ", DST = " << ts.tm_isdst << '\n';
    tout("*** tm after gmtime", ts);

    localTime = jan + zone + dst;           // reconstruct the local time
    cout << "Local time (reconstructed): " << 
            put_time(gmtime_r(&localTime, &ts), "%c") << '\n';

    cout << '\n';
    

    ts = ts0;
    ts.tm_mon = 6;
    cout << "   Local time: Jul 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    time_t jul = utcTime(&ts, &dst);

    gmtime_r(&jul, &ts);
    cout << "Jul.: " << jul << ": " <<  // + dst shift
            put_time(&ts, "%c") << 
            ", DST = " << ts.tm_isdst << '\n';      // DST shift unknown.
    tout("tm after gmtime", ts);

    localTime = jul + zone + dst;           // reconstruct the local time
    cout << "Local time (reconstructed): " << 
            put_time(gmtime_r(&localTime, &ts), "%c") << '\n';

    cout << '\n';

    cout << 
        "When DST is active, the returned time is DST seconds too large"
                                                                        R"R(

The way to compute UTC is:
    1. call mktime to obtain time in UTC + dst shift
    2. if tm_isdst > 0, then subtract the DST shift to obtain UTC
    3. if DST must be remembered, store tm_isdst in a variable.

To show UTC call gmtime_r on the returned time. 
Note that gmtime_r sets tm_isdst to 0.

To convert the received UTC time back to local time in a tm:
    1. Compute the sum of the zone shift, the dst shift and the time 
        returned by utcTime
    2. Call gmtime_r for this sum.

)R";

    ts = ts0;                           // assume this already is UTC

    cout << "   UTC time: Jan 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    ts.tm_sec += zone;                  // correction for the zone shift
    jan = utcTime(&ts, &dst);           // mktime returns ts's UTC - zonesecs
    jan += dst;
    dst = 0;

    gmtime_r(&jan, &ts);
    cout << "Jan.: " << jan << ": " <<  // + dst shift
            put_time(&ts, "%c") << 
            ", DST = " << ts.tm_isdst << '\n';
    tout("*** tm after gmtime", ts);

    cout << '\n';

    ts = ts0;                           // assume this already is UTC
    ts.tm_mon = 6;

    cout << "   UTC time: Jul 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    ts.tm_sec += zone;                  // correction for the zone shift
    jul = utcTime(&ts, &dst);           // mktime returns ts's UTC - zonesecs
    jul += dst;
    dst = 0;

    gmtime_r(&jul, &ts);
    cout << "Jul.: " << jul << ": " <<  // + dst shift
            put_time(&ts, "%c") << 
            ", DST = " << ts.tm_isdst << '\n';
    tout("*** tm after gmtime", ts);

}










