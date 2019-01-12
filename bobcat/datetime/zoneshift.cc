#include "datetime.ih"

// static 
int DateTime::zoneShift(string const &zone)
{
    auto iter = s_zone.find(zone);
    if (iter == s_zone.end())
        throw Exception{ 1 } << "Time zone `" << zone << 
                    "' not registered (maybe use addZone or readZone?)";

    return iter->second;
}
