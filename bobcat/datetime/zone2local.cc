#include "datetime.ih"

void DateTime::zone2local(int tzShift)      // in minutes
{
    d_tm.tm_min -= tzShift;
    utc2local();
}

