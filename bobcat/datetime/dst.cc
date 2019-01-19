#include "datetime.ih"

DateTime::TriVal DateTime::dst() const
{
    return DSTInfo::get(this).activeDST() ? YES : NO;
}
