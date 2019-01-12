#include "datetime.ih"

void DateTime::zoneOut(int tzShift)
{
    d_zone = asSeconds(tzShift);

    if (d_dst > 0)
        d_zone -= 3600;
}
