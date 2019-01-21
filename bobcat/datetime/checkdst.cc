#include "datetime.ih"

int DateTime::checkDST() const
{
    return Pimpl::get(this).activeDST() ? d_dst : 0;
}
