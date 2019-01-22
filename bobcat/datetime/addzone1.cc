#include "datetime.ih"

// static
void DateTime::addZone(string const &name, int zoneMinutes,
                                           DSTSpec const &spec)
{
    ZoneNames::addZone(name, ZoneData{ zoneMinutes, spec } );
}
