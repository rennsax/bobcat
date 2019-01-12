#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int tzShift)
:
    d_type(LOCALTIME)
{
    Parse parse{ parseTime(timeStr) };

    if (not parse.zone)
        utc2zone(tzShift);
    else
        zone2zone(parse.tzShift, tzShift);

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}
