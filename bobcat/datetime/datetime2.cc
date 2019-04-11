#include "datetime.ih"

    // copy uses memcpy to copy other's data to *this
DateTime::DateTime(DateTime const &other)
{
    Pimpl::copy(this, other);
}
