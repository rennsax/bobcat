#include "datetime.ih"

// static
void DateTime::addZone(string const &name, int minutes)
{
    ZoneNames::addZone(name, asSeconds(minutes) / 60);
}
