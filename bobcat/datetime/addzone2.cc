#include "datetime.ih"

// static
void DateTime::ZoneNames::addZone(string const &name, int minutes)
{
    s_zone[name] = minutes;
}
