#include "datetime.ih"

// static
DateTime::Pimpl const &DateTime::Pimpl::get(DateTime const *ptr)
{
    s_mutex.lock();
    auto &pimpl = *s_pimpl.find(ptr)->second; 
    s_mutex.unlock();

    return pimpl;
}
