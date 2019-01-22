#include "datetime.ih"

    // d_tm utc, initialize utc

void DateTime::utc2utc()            // tm = time
{
    d_tm.tm_sec += defaultZoneSecs();  // add default zone

    d_time = mktime(&d_tm);        // mktime returns d_tm's UTC - zonesecs

    d_zone = 0;
    d_dst = 0;
}
