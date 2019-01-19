#include "datetime.ih"

// static
void DateTime::DSTInfo::move(DateTime *ptr, DateTime &&tmp)
{
    s_mutex.lock();

    memcpy(static_cast<void *>(ptr), &tmp, sizeof(DateTime));
    s_pimpl[ptr] = std::move(s_pimpl.find(&tmp)->second);

    s_mutex.unlock();
}

