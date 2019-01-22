#include "datetime.ih"

    //  Mon, 03 Dec 2018 13:29:11 +0100     `Mon,' has already been read.

void DateTime::Parse::dateR()
{
    char sign;
    int zoneMinutes;
    string month;
    char sep;

    if (
            not (
                d_in >> d_dt.d_tm.tm_mday >> month >> d_dt.d_tm.tm_year >>
                    d_dt.d_tm.tm_hour >> sep >> d_dt.d_tm.tm_min >> sep >>
                    d_dt.d_tm.tm_sec >> sign >> zoneMinutes
            )
        or
            not setTmMonth(month)
    )
        throw 1;                                // format error, handled by

    set(zoneMinutes / 100 * 60 + zoneMinutes % 100, sign);
}
