#include "datetime.ih"

DateTime &DateTime::install(DateTime &tmp)
{
    DSTInfo::refreshDST(&tmp);
    tmp.refreshTM();
    swap(tmp);
    return *this;
}
