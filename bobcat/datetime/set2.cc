#include "datetime.ih"

void DateTime::Parse::set(int minutes, int sign)
{
    d_usesZone = true;
    d_zoneMinutes = minutes;

    if (sign == '-')
        d_zoneMinutes = -d_zoneMinutes;
}
