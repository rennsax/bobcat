#include "datetime.ih"

DateTime::TM const *DateTime::displayTM() const
{
    time_t seconds = d_time;

    if (d_type == LOCALTIME)
        seconds += d_zone + d_dst;

    return gmtime_r(&seconds, &d_tm);
}

