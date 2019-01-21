#include "datetime.ih"

DateTime::DateTime(DateTime &&tmp)
{
    ZoneInfo::move(this, move(tmp));
}
