#include "datetime.ih"

// time provides UTC time in seconds, zoneMinutes (in minutes) sets d_zone

                                                // zoneMinutes in minutes
DateTime::DateTime(time_t time, int zoneMinutes, DSTSpec const &spec)
:
    d_time(time),
    d_zone(asSeconds(zoneMinutes))
{
    iniLocal(spec);
}
