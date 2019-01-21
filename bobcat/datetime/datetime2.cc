#include "datetime.ih"

DateTime::DateTime(DateTime const &other)
{
    Pimpl::copy(this, other);
}
