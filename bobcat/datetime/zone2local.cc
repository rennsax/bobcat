#include "datetime.ih"

void DateTime::zone2local(int zoneMinutes)      // in minutes
{
    d_tm.tm_min -= zoneMinutes;
    utc2local();
}
