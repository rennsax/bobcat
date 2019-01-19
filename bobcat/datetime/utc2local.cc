#include "datetime.ih"

void DateTime::utc2local()
{
    utc2utc();
    d_zone = defaultZoneSecs();
}
