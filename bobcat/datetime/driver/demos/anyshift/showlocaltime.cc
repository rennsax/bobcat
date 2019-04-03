#include "main.ih"

void showLocalTime()
{
    time_t current = time(0) + localZone + localDST;

    tm ts;

    gmtime_r(&current, &ts);

    showTM(ts, "Local time");
}

