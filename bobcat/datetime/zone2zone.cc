#include "datetime.ih"

void DateTime::zone2zone(int tzIn, int tzOut)
{
    zone2utc(tzIn);
    zoneOut(tzOut);
}

