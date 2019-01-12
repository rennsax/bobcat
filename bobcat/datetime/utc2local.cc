#include "datetime.ih"

void DateTime::utc2local()
{
    d_dst = utc2utc();
    d_zone = zone();
}
