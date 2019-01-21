#include "datetime.ih"

void DateTime::swap(DateTime &other)
{
    ZoneInfo::swap(*this, other);
}
