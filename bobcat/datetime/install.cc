#include "datetime.ih"

DateTime &DateTime::install(DateTime &tmp)
{
    ZoneInfo::refreshDST(&tmp);
    tmp.refreshTM();
    swap(tmp);
    return *this;
}
