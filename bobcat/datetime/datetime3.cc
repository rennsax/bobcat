#include "datetime.ih"

DateTime::DateTime(DateTime &&tmp)
{
    Pimpl::move(this, move(tmp));
}
