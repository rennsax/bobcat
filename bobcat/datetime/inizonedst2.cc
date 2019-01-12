#include "datetime.ih"

void DateTime::iniZoneDst(int tzShift)
{
    d_type = LOCALTIME;
    d_zone = asSeconds(tzShift) - setDst(d_time);

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}
