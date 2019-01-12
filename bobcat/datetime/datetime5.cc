#include "datetime.ih"

//  time: time in seconds since the epoch
//      UTC: merely time
//      LOCALTIME: sets  d_zone (zone()), and d_dst

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_time(time)
{
    iniZoneDst();                               // 1.cc
}
