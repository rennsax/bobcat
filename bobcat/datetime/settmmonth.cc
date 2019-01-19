#include "datetime.ih"

bool DateTime::setTmMonth(string const &mon)
{
    return (d_tm.tm_mon = find(s_month, s_month + 12, mon) - s_month) != 12;
}
