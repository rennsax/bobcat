#include "datetime.ih"

void DateTime::Pimpl::erase(DateTime const *ptr)
{
    s_mutex.lock();
    s_pimpl.erase(ptr);
    s_mutex.unlock();
}
