#include "datetime.ih"

bool DateTime::Parse::setTmMonth(string const &mon) const
{
    return (d_dt.d_tm.tm_mon =
                find(DateTime::s_month, DateTime::s_month + 12, mon)
                - DateTime::s_month
            ) != 12;
}
