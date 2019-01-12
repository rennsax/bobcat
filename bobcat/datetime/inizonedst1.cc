#include "datetime.ih"

void DateTime::iniZoneDst()
{
    if (d_type == UTC)
    {
        d_zone = 0;
        d_dst = NO;
    }
    else
    {
        d_zone = zone();                    // default time zone
        setDst(d_time);
    }

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}
