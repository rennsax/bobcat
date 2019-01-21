#include "datetime.ih"

// static
void DateTime::ZoneInfo::copy(DateTime *ptr, DateTime const &other)
{
    s_mutex.lock();
    memcpy(static_cast<void *>(ptr), &other, sizeof(DateTime));
    s_pimpl[ptr] = unique_ptr<ZoneInfo>{ 
                        new ZoneInfo{ *s_pimpl.find(&other)->second } };
    s_mutex.unlock();
}

