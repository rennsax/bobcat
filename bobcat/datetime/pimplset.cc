#include "datetime.ih"

// static
void  DateTime::Pimpl::set(DateTime const *ptr, Zone const &spec)
{
    Pimpl *dstPtr = new Pimpl{ spec };

//    dstPtr->updateDST(ptr->d_utcSec);

    s_mutex.lock();

    s_pimpl[ptr] = unique_ptr<Pimpl>{ dstPtr };

    s_mutex.unlock();
}
