#include "datetime.ih"

DateTime::TriVal DateTime::dst() const
{
    return ZoneInfo::get(this).activeDST() ? YES : NO;
}
