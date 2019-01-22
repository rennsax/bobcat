#include "datetime.ih"

DateTime DateTime::to(TimeType type) const
{
    return DateTime{ d_time, type };
}
