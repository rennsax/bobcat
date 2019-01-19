#include "datetime.ih"

// static
DateTime::DSTInfo &DateTime::DSTInfo::get(DateTime const *ptr)
{
    s_mutex.lock();
    auto &info = *s_pimpl.find(ptr)->second;
    s_mutex.unlock();

    return info;
}
