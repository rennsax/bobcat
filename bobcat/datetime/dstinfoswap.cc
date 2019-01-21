#include "datetime.ih"

void DateTime::ZoneInfo::swap(DateTime &lhs, DateTime &rhs)
{
    s_mutex.lock();

    fswap(lhs, rhs);
    s_pimpl.find(&lhs)->second.swap(s_pimpl.find(&rhs)->second);

    s_mutex.unlock();
}
