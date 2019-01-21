#include "datetime.ih"

DateTime::TriVal DateTime::dst() const
{
    return Pimpl::get(this).activeDST() ? YES : NO;
}
