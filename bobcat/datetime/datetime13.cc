#include "datetime.ih"

DateTime::DateTime(istream &in, TimeType type)
:
    d_type(type)
{
    Parse parse{ in, this };

    if (parse.usesZone())
    {
        if (type == UTC)
            zone2utc(parse.zoneMinutes());
        else
            zone2local(parse.zoneMinutes());
    }
    else
    {
        if (type == UTC)
            utc2utc();
        else
            local2local();
    }

    iniZoneDstPimpl();
}
