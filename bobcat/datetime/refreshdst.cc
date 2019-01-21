#include "datetime.ih"

// static
void DateTime::ZoneInfo::refreshDST(DateTime const *ptr)
{
    get(ptr).updateDST(ptr->d_time);
}
