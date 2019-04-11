#include "datetime.ih"

DateTime::TriVal DateTime::dst() const
{
    return d_tm.tm_isdst ? YES : NO;
}
