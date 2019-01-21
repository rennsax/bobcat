#include "datetime.ih"

void DateTime::Pimpl::updateDST(time_t utcSecs)
{
    TM ts;
    setDSTactive(localtime_r(&utcSecs, &ts));
}
