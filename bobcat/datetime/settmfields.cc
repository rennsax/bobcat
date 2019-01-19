#include "datetime.ih"

DateTime &DateTime::setTMfields(TM const &fields, 
                           void (*modifier)(TM &dest, TM const &src))
try
{
    DateTime tmp{ *this };                  // local copy
    
    gmtime_r(&d_time, &tmp.d_tm);           // UTC now in tmp.d_tm

    (*modifier)(tmp.d_tm, fields);

    tmp.d_tm.tm_sec += defaultZoneSecs();   // add the local zone (for mktime)

    tmp.d_time = mktime(&tmp.d_tm);         // update tmp.d_time's UTC secs.

    if (tmp.d_time == -1)                   // test if mktime's OK
        throw 1;

    return install(tmp);
}
catch (...)
{
    timeException();    
}




