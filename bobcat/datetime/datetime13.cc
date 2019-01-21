#include "datetime.ih"

DateTime::DateTime(istream &in, TimeType type)
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
            zone2utc(parse.zoneMinutes);
        else
            zone2local(parse.zoneMinutes);
    }        

    iniZoneDstZoneInfo();
}




