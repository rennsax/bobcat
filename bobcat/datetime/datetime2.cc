#include "datetime.ih"

DateTime::DateTime(DateTime const &other)
{
    ZoneInfo::copy(this, other);
}
