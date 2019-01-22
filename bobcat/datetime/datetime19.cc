#include "datetime.ih"

DateTime::DateTime(istream &in, int zoneMinutes, DSTSpec const &spec)
:
    d_type(LOCALTIME)
{
    Parse parse{ in, this };

    if (parse.usesZone())
        zone2zone(parse.zoneMinutes(), zoneMinutes);
    else
        utc2zone(zoneMinutes);

    iniPimplTM(spec);
}
