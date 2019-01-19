#include "datetime.ih"

DateTime::~DateTime()
{
    DSTInfo::erase(this);
}
