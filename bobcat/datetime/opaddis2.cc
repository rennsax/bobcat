#include "datetime.ih"

DateTime &DateTime::operator+=(TM const &fields)
{
    return setTMfields(fields, addFields);
}
