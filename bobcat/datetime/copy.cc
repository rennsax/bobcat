#include "datetime.ih"

// static
void DateTime::Pimpl::copy(DateTime *ptr, DateTime const &other)
{
    s_mutex.lock();
    memcpy(static_cast<void *>(ptr), &other, sizeof(DateTime));
    s_pimpl[ptr] = unique_ptr<Pimpl>{ 
                        new Pimpl{ *s_pimpl.find(&other)->second } };
    s_mutex.unlock();
}

