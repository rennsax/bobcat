#include "datetime.ih"

//     struct tm ts = {0, 0, 10, 5, 6, 109, 0, 0, 1};
//      dst and day-of-year fields ignored.
//      ts defines a UTC time point, zoneMinutes is added to obtain local time

DateTime::DateTime(TM const &utcTm, int zoneMinutes, DSTSpec const &spec)
:
    d_type(LOCALTIME),
    d_tm(utcTm)
{
    d_tm.tm_year -= 1900;
    utc2zone(zoneMinutes);

    iniDSTInfoTM(spec);
}

