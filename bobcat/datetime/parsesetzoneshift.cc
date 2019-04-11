#include "datetime.ih"

void DateTime::Parse::setZoneShift(bool negative, int hours, int minutes)
{
    d_zoneShift = hours * 3600 + minutes * 60;
    if (negative)
        d_zoneShift = -d_zoneShift;
}
