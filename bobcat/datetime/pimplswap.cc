#include "datetime.ih"

void DateTime::Pimpl::swap(DateTime &lhs, DateTime &rhs)
{
    s_mutex.lock();

    fswap(lhs, rhs);                    // swap the DateTime objects

                                        // swap their Pimpl-data
    s_pimpl.find(&lhs)->second.swap(s_pimpl.find(&rhs)->second);

    s_mutex.unlock();
}
