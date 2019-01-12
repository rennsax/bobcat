#include "datetime.ih"

DateTime::DateTime(DateTime const &other)
{
    memcpy(this, &other, sizeof(DateTime));
    setZoneData(s_pimpl[&other]);
}
