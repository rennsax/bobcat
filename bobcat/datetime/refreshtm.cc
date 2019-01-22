#include "datetime.ih"

void DateTime::refreshTM()
{
    time_t seconds = d_time;

    if (d_type == LOCALTIME)
        seconds += d_zone + checkDST();

    if (gmtime_r(&seconds, &d_tm) == 0)
        timeException();
}
