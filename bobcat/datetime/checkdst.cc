#include "datetime.ih"

int DateTime::checkDST() const
{
    return DSTInfo::get(this).activeDST() ? d_dst : 0;
}
