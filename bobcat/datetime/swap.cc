#include "datetime.ih"

void DateTime::swap(DateTime &other)
{
    s_mutex.lock();

    fswap(s_pimpl[this], s_pimpl[&other]);
    fswap(*this, other);

    s_mutex.unlock();
}
