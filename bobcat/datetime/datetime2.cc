#include "datetime.ih"

DateTime::DateTime(DateTime const &other)
{
    DSTInfo::copy(this, other);
}
