#include "datetime.ih"

// See README

// tm is UTC when type == UTC, and localtime if type == LOCALTIME

DateTime::DateTime(TM const &tm, TimeType type)
:
    d_type(type),
    d_tm(tm)
{
    d_tm.tm_year -= 1900;

    if (d_type == UTC)
        utc2utc();
    else
        local2local();

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}

