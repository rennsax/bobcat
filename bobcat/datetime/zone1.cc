#include "datetime.ih"

// static
int DateTime::zone()
{
    TM ts;
    time_t zero = 0;
    return -mktime(gmtime_r(&zero, &ts));
}




