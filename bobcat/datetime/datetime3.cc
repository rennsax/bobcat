#include "datetime.ih"

DateTime::DateTime(DateTime &&tmp)
{
    DSTInfo::move(this, move(tmp));
}
