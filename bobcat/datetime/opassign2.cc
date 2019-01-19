#include "datetime.ih"

DateTime &DateTime::operator=(DateTime &&tmp)
{
    swap(tmp);
    return *this;
}
