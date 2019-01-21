#include "datetime.ih"

DateTime::ZoneData::ZoneData(int minutes, DSTSpec const &spec)
:
    d_zoneMinutes(minutes),
    d_spec(spec)
{}
