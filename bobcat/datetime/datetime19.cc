#include "datetime.ih"

DateTime::DateTime(istream &in, int zoneMinutes, DSTSpec const &spec)
:
    d_type(LOCALTIME)
{
    Parse parse{ parseStream(in) };

    if (not parse.zone)
        utc2zone(zoneMinutes);
    else
        zone2zone(parse.zoneMinutes, zoneMinutes);

    iniPimplTM(spec);
}
