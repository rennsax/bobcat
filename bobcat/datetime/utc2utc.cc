#include "datetime.ih"

    // d_tm utc, initialize utc

int DateTime::utc2utc()            // tm = time 
{
    d_tm.tm_sec += zone();         // add default zone

    d_time = mktime(&d_tm);        // mktime returns d_tm's UTC - zonesecs

    d_zone = 0;
    d_dst = 0;

    return d_tm.tm_isdst > 0 ? 3600 : 0;
}
