#include "datetime.ih"

// static
DateTime::ZoneInfo &DateTime::ZoneInfo::get(DateTime const *ptr)
{
    s_mutex.lock();
    auto &info = *s_pimpl.find(ptr)->second;
    s_mutex.unlock();

    return info;
}
