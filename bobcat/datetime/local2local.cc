#include "datetime.ih"

void DateTime::local2local()
{
    d_dst = local2utc();
    d_zone = defaultZoneSecs();
}
