#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type)
:
    d_type(type)
{
    Parse parse{ parseTime(timeStr) };

    if (not parse.zone)
    {
        if (type == UTC)
            utc2utc();
        else
            local2local();
    }
    else
    {
        if (type == UTC)
            zone2utc(parse.tzShift);
        else
            zone2local(parse.tzShift);
    }        

    setZoneData(ZoneData{ static_cast<int>(d_zone), d_dst });
}
