#include "datetime.ih"

// static
int DateTime::minutes(string const &zoneName)
{
    return ZoneNames::minutes(zoneName);
}
