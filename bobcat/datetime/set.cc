#include "datetime.ih"

// static
int DateTime::DSTInfo::set(DateTime const *ptr, DSTSpec const &spec)
{
    DSTInfo *dstPtr = new DSTInfo{ spec };

    dstPtr->updateDST(ptr->d_time);
//    TM ts;
//    dstPtr->setDSTactive(localtime_r(&ptr->d_time, &ts));

    s_mutex.lock();
    s_pimpl[ptr] = unique_ptr<DSTInfo>{ dstPtr };
    s_mutex.unlock();

    return spec.d_dstSeconds;
}
