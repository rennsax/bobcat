#include "datetime.ih"

DateTime::DateTime(TimeType type, istream &in)
:
    d_type(type)
{
    Parse parse{ parseStream(in) };

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




