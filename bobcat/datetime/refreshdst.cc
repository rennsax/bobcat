#include "datetime.ih"

// static
void DateTime::DSTInfo::refreshDST(DateTime const *ptr)
{
    get(ptr).updateDST(ptr->d_time);
}
