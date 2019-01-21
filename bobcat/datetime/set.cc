#include "datetime.ih"

// static
int DateTime::Pimpl::set(DateTime const *ptr, DSTSpec const &spec)
{
    Pimpl *dstPtr = new Pimpl{ spec };

    dstPtr->updateDST(ptr->d_time);

    s_mutex.lock();
    s_pimpl[ptr] = unique_ptr<Pimpl>{ dstPtr };
    s_mutex.unlock();

    return spec.d_dstSeconds;
}
