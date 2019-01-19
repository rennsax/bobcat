#include "datetime.ih"

void DateTime::DSTInfo::setDSTactive(tm *ts)
{
    if (not ts)
        throw Exception{ 1 } << "Cannot obtain local time information";

    d_DSTactive = 
            not d_dates.d_supportsDST ? 
                false 
        : 
            d_dates.d_startDay == 0 ?   // startday 0: ts's tm_isdst is used
                ts->tm_isdst 
        :
                                        // with equal months compare mdays
                                        // otherwise mon must lie within 
                                        // startMon .. endMon
            d_dates.d_startMon == ts->tm_mon and 
                                  d_dates.d_endMon == ts->tm_mon ?
            d_dates.d_startDay <= ts->tm_mday and 
                                  ts->tm_mday <= d_dates.d_endDay
        :
            d_dates.d_startMon <= ts->tm_mon and 
                                  ts->tm_mon <= d_dates.d_endMon;
}
// cerr << "\nDSTactive: " <<
//     (int)d_dates.d_startMon << 
//     '/' << (int)d_dates.d_startDay <<
//     '-' << (int)d_dates.d_endMon << 
//     '/' << (int)d_dates.d_endDay <<
//     ", " << ts->tm_mon <<
//     '/' << ts->tm_mday << ":  " << b1 << ' ' << b2 << ' ' << b3 << '\n';
