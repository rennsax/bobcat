#include "datetime.ih"

void DateTime::ZoneInfo::updateDST(time_t utcSecs)
{
    TM ts;
    setDSTactive(localtime_r(&utcSecs, &ts));
}
