#include "datetime.ih"

// static
void DateTime::addZone(string const &name, DSTSpec const &spec)
{
    ZoneNames::addZone(name, spec);
}
