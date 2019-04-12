#include "datetime.ih"

// static
time_t DateTime::utcForZone(std::string const &zoneSpec, TM &tm)
{
    setTZ(zoneSpec);
    time_t ret = mktime(&tm);
    resetTZ();

    return ret;
}

