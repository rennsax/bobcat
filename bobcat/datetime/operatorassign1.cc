#include "datetime.ih"

DateTime &DateTime::operator=(DateTime const &other)
{
    return *this = DateTime{ other };
}
