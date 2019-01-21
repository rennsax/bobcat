#include "datetime.ih"

DateTime::~DateTime()
{
    Pimpl::erase(this);
}
