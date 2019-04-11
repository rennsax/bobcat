#include "datetime.ih"

    // from utc seconds + current zone to TM
    // use utcFromTM to obtain UTC seconds given zone and spec. in TM
struct tm const &DateTime::assignTM() const
{
    setenv("TZ", 
            Pimpl::get(this).spec().c_str(), 
            1);   // use tzSpec as TZ (empty is UTC)
    tzset();

    localtime_r(&d_utcSec, &d_tm);

    if (Zone::defaultTZ().empty())
        unsetenv("TZ");    
    else
        setenv("TZ", Zone::defaultTZ().c_str(), 1);

    tzset();

    return d_tm;
}
