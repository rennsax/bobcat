#include "datetime.ih"

int DateTime::local2utc()
{
    int ret;

    d_time = mktime(&d_tm);             // mktime returns d_tm's UTC - zonesecs

    if (d_tm.tm_isdst <= 0)
        ret = 0;
    else
    {
        ret = 3600;
        d_time -= 3600;
    }

    d_zone = 0;
    d_dst = 0;

    return ret;
}
