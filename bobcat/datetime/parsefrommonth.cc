#include "datetime.ih"

// Day name already read:
//
//        Mon Dec 3 13:29:11 2018           spec. #1: d_type UTC: UTC time, 
//                                                    LOCALTIME: local time
//  or:
//        Mon Dec 3 13:29:11 CET 2018       spec. #2, 

DateTime::Parse DateTime::parseFromMonth(istream &in)
{
    string month;
    string zoneOrYear;
    char sep;

    if (                                    // get all fields through tz-name
            not (                           // or year
            in >> month >> d_tm.tm_mday >>
                d_tm.tm_hour >> sep >> d_tm.tm_min >> sep >> d_tm.tm_sec >>
                zoneOrYear
            )
        or                                     
            not setTmMonth(month)           // validate month name
    )
        throw 1;                            // format error -> iniParse()


    if (isdigit(zoneOrYear[0]))             // got a year: spec. #1
    {
        d_tm.tm_year = stoul(zoneOrYear);
        return Parse{};
    }

    if (not (in >> d_tm.tm_year))
        throw 1;

    return Parse{ zoneShift(zoneOrYear) };   // "Mon Dec 3 13:29:11 CET 2018"
}



