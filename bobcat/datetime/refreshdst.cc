#include "datetime.ih"

// static
void DateTime::Pimpl::refreshDST(DateTime const *ptr)
{
    get(ptr).updateDST(ptr->d_time);
}
