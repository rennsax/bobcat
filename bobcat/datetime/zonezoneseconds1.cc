#include "datetime.ih"

// static
int DateTime::Zone::zoneSeconds(std::string const &spec)
{
    time_t seconds = 0;
    TM tm;
    gmtime_r(&seconds, &tm);
    return - mktime(&tm);
}
