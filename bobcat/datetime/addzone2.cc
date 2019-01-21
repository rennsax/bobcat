#include "datetime.ih"

// static
void DateTime::ZoneNames::addZone(string const &name, ZoneData const &info)
{
    s_zone[name] = info;
}
