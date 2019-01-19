#include "datetime.ih"

void DateTime::DSTInfo::erase(DateTime const *ptr)
{
    s_mutex.lock();
    s_pimpl.erase(ptr);
    s_mutex.unlock();
}
