#include "datetime.ih"

DateTime::~DateTime()
{
    s_mutex.lock();
    s_pimpl.erase(this);
    s_mutex.unlock();
}
