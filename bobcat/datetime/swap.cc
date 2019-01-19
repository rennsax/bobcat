#include "datetime.ih"

void DateTime::swap(DateTime &other)
{
    DSTInfo::swap(*this, other);
}
