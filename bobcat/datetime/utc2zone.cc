#include "datetime.ih"

void DateTime::utc2zone(int tzMinutes)     // in minutes
{
    utc2utc();
    d_zone = asSeconds(tzMinutes);
//    zoneOut(zoneMinutes);
}
