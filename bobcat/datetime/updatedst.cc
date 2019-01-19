#include "datetime.ih"

void DateTime::DSTInfo::updateDST(time_t utcSecs)
{
    TM ts;
    setDSTactive(localtime_r(&utcSecs, &ts));
}
