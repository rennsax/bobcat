#include "datetime.ih"

void DateTime::zone2utc(int zoneMinutes)
{
    d_tm.tm_min -= zoneMinutes;
    utc2utc();
}

