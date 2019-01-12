#include "datetime.ih"

    //  Mon, 03 Dec 2018 13:29:11 +0100     `Mon,' has already been read.

DateTime::Parse DateTime::parseDateR(istream &in)
{
    char sign;
    int tzShift;
    string month;
    char sep;

    if (
            not (
                in >> d_tm.tm_mday >> month >> d_tm.tm_year >> 
                    d_tm.tm_hour >> sep >> d_tm.tm_min >> sep >> 
                                                                d_tm.tm_sec >>
                    sign >> tzShift
            )
        or 
            not setTmMonth(month)
    )
        throw 1;                                // format error, handled by

    return Parse{ sign, tzShift / 100 * 60 + tzShift % 100 };
}



