#include "datetime.ih"

void DateTime::zone2utc(int tzShift)
{
    d_tm.tm_min -= tzShift;
    utc2utc();
}

