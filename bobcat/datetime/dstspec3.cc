#include "datetime.ih"

DateTime::DSTSpec::DSTSpec(string const &begin, string const &end, 
                           int dstMinutes)
try
:
    d_dstSeconds(asSeconds(dstMinutes))
{
    d_dates.d_supportsDST = true;

    split(&d_dates.d_startMon, &d_dates.d_startDay, begin);
    split(&d_dates.d_endMon, &d_dates.d_endDay, end);

    if (begin > end)
        throw 1;
}
catch (...)
{
    throw Exception{ 1 } << "Invalid DSTSpec";
}
