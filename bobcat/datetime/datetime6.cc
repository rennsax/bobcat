#include "datetime.ih"

//  time: time in seconds since the epoch
//      UTC: merely time, zone = 0,         supportsDST = false
//      LOCALTIME: sets  d_zone (zone()),   supportsDST, d_dst: standard

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_time(time)
{
    iniZoneDstDSTInfo();
}
