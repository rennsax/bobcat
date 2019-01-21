#include "datetime.ih"

DateTime::ZoneInfo::ZoneInfo(int minutes, DSTSpec const &spec)
:
    d_dates(spec.d_dates),
    d_zoneShiftSeconds(asSeconds(minutes))
{}
