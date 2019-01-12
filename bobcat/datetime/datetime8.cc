#include "datetime.ih"

//     struct tm ts = {0, 0, 10, 5, 6, 109, 0, 0, 1};
//      dst and day-of-year fields ignored.
//      ts defines a UTC time point, tzShift is added to obtain local time

DateTime::DateTime(TM const &utcTm, int tzShift)
:
    d_type(LOCALTIME),
    d_tm(utcTm)
{
    d_tm.tm_year -= 1900;
    utc2zone(tzShift);

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}

