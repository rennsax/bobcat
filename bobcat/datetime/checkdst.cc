#include "datetime.ih"

int DateTime::checkDST() const
{
    return ZoneInfo::get(this).activeDST() ? d_dst : 0;
}
