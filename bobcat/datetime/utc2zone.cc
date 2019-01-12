#include "datetime.ih"

void DateTime::utc2zone(int tzShift)     // in minutes
{
    d_dst = utc2utc();
    zoneOut(tzShift);
}

