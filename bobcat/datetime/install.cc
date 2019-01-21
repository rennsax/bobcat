#include "datetime.ih"

DateTime &DateTime::install(DateTime &tmp)
{
    Pimpl::refreshDST(&tmp);
    tmp.refreshTM();
    swap(tmp);
    return *this;
}
