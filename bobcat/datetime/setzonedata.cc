#include "datetime.ih"

void DateTime::setZoneData(ZoneData const &zoneData)
{
    s_mutex.lock();
    s_pimpl[this] = zoneData;
    s_mutex.unlock();
}
