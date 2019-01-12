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

time_t utc;
time_t zone;
int dst;
bool dstActive;

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
        ",  day "  << ts.tm_mday << '\n';
}

time_t defZone = currentZoneShift();

void utc2utc(tm *ts)
{
    ts->tm_sec += defZone;          // add default zone

    utc = mktime(ts);            // mktime returns ts's UTC - zonesecs

    dstActive = ts->tm_isdst > 0;

    zone = 0;
    dst = 0;
}

void zoneOut(int outZone)
{
    zone = outZone * 60;
    if (dstActive)
    {
        zone -= 3600;
        dst = 3600;
    }
}


void utc2zone(tm *ts, int zoneShift)    // in minutes
{
    utc2utc(ts);
    zoneOut(zoneShift);
}

int main()
{
    tm ts = ts0;
    time_t showTime;

    cout << "   UTC time: Jan 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    utc2zone(&ts, 4 * 60);

    showTime = utc + zone + dst;
    gmtime_r(&showTime, &ts);
    cout << "Zone +4:00: " << put_time(&ts, "%c") << ", DST: " <<
                                                    dstActive << "\n\n";


    ts = ts0;                           // assume this already is UTC
    ts.tm_mon = 6;

    cout << "   UTC time: Jul 1, 2018 12:00:\n";
    tout("*** input tm", ts);

    utc2zone(&ts, 4 * 60);

    showTime = utc + zone + dst;
    gmtime_r(&showTime, &ts);
    cout << "Zone +4:00: " << put_time(&ts, "%c") << ", DST: " <<
                                                    dstActive << "\n\n";
}










