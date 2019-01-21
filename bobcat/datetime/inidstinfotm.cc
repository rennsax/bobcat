#include "datetime.ih"

void DateTime::iniZoneInfoTM(DSTSpec const &spec)
{
    d_dst = ZoneInfo::set(this, spec);           // set.cc
    refreshTM();
}
