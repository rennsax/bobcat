#include "datetime.ih"

// Day name already read:
//
//        Mon Dec 3 13:29:11 2018           spec. #1: d_type UTC: UTC time,
//                                                    LOCALTIME: local time
//  or:
//        Mon Dec 3 13:29:11 CET 2018       spec. #2,

void DateTime::Parse::fromMonth()
{
    string month;
    string zoneOrYear;
    char sep;

    if (                                    // get all fields through tz-name
            not (                           // or year
            d_in >> month >> d_dt.d_tm.tm_mday >>
                d_dt.d_tm.tm_hour >> sep >> d_dt.d_tm.tm_min >> sep >>
                d_dt.d_tm.tm_sec >> zoneOrYear
            )
        or
            not setTmMonth(month)           // validate month name
    )
        throw 1;                            // format error -> iniParse()

    if (isdigit(zoneOrYear[0]))             // got a year: spec. #1
    {                                       // "Mon Dec 3 13:29:11 CET 2018"
        d_dt.d_tm.tm_year = stoul(zoneOrYear);
        return;
    }

    if (not (d_in >> d_dt.d_tm.tm_year))
        throw 1;

    set(ZoneNames::minutes(zoneOrYear));
}
