#include "datetime.ih"

// static
void DateTime::ZoneNames::addZone(string const &name, DSTSpec const &spec)
{
    s_zone[name] = spec;
}
