#include "datetime.ih"

// static
void DateTime::addFields(TM &dest, TM const &src)
{
    dest.tm_sec  += src.tm_sec;      // update the fields
    dest.tm_min  += src.tm_min;
    dest.tm_hour += src.tm_hour;
    dest.tm_mday += src.tm_mday;
    dest.tm_mon  += src.tm_mon;
    dest.tm_year += src.tm_year;
}
