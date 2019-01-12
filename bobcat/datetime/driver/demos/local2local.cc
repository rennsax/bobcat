#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

    tm ts0 =                 // considered UTC time
    {
        0,
        0,
        12,                // hr
        1,                 // daynr
        0,                 // Jan
        118,
    };

time_t currentZoneShift() 
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
        ",  day "  << ts.tm_mday    << '\n';
}

time_t defZone = currentZoneShift();

time_t utc;
time_t zone;
int dst;
bool dstActive;


int local2utc(tm *ts)           // returns dstShift
{
    int ret;

    utc = mktime(ts);            // mktime returns ts's UTC - zonesecs

    if (ts->tm_isdst <= 0)
        ret = 0;
    else
    {
        ret = 3600;
        utc -= 3600;
    }

    zone = 0;
    dst = 0;

    return ret;
}

void local2local(tm *tm)
{
    dst = local2utc(tm);
    zone = defZone;
}

int main()
{
    tm ts = ts0;
    time_t showTime;

    cout << "   LOCAL time: Jan 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    local2local(&ts);

    showTime = utc + zone + dst;
    gmtime_r(&showTime, &ts);
    cout << "Jan. LOCAL: " << put_time(&ts, "%c") << ", DST: " <<
                                                    (dst > 0) << "\n\n";


    ts = ts0;                           // assume this already is LOCAL
    ts.tm_mon = 6;

    cout << "   LOCAL time: Jul 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    local2local(&ts);

    showTime = utc + zone + dst;
    gmtime_r(&showTime, &ts);
    cout << "Jul. LOCAL: " << put_time(&ts, "%c") << ", DST: " <<
                                                    (dst > 0) << "\n\n";
}










