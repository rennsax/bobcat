#include "datetime.ih"

// static
time_t DateTime::utcForZone(char const *zoneSpec, TM &tm)
{
    setenv("TZ", zoneSpec, 1);
    tzset();

    time_t ret = mktime(&tm);

    if (Zone::defaultTZ().empty())
        unsetenv("TZ");    
    else
        setenv("TZ", Zone::defaultTZ().c_str(), 1);
    tzset();

    return ret;
}

