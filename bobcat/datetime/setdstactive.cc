#include "datetime.ih"

void DateTime::Pimpl::setDSTactive(tm *ts)
{
    if (not ts)
        throw Exception{ 1 } << "Cannot obtain local time information";

    d_DSTactive =
            not supportsDST() ?
                false
        :
            d_spec.startDay() == 0 ?    // startday 0: ts's tm_isdst is used
                ts->tm_isdst
        :
                                        // with equal months compare mdays
                                        // otherwise mon must lie within
                                        // startMon .. endMon
            d_spec.startMon() == ts->tm_mon and
                                  d_spec.endMon() == ts->tm_mon ?
            d_spec.startDay() <= ts->tm_mday and
                                  ts->tm_mday <= d_spec.endDay()
        :
            d_spec.startMon() <= ts->tm_mon and
                                  ts->tm_mon <= d_spec.endMon();
}
// cerr << "\nDSTactive: " <<
//     (int)d_startMon <<
//     '/' << (int)d_startDay <<
//     '-' << (int)d_endMon <<
//     '/' << (int)d_endDay <<
//     ", " << ts->tm_mon <<
//     '/' << ts->tm_mday << ":  " << b1 << ' ' << b2 << ' ' << b3 << '\n';
