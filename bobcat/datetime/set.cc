#include "datetime.ih"

// static
int DateTime::ZoneInfo::set(DateTime const *ptr, DSTSpec const &spec)
{
    ZoneInfo *dstPtr = new ZoneInfo{ spec };

    dstPtr->updateDST(ptr->d_time);
//    TM ts;
//    dstPtr->setDSTactive(localtime_r(&ptr->d_time, &ts));

    s_mutex.lock();
    s_pimpl[ptr] = unique_ptr<ZoneInfo>{ dstPtr };
    s_mutex.unlock();

    return spec.d_dstSeconds;
}
