#include "datetime.ih"

    // obtain UTC seconds given zone and spec. in TM
    // use assignTM to set TM from utc seconds + current zone
time_t DateTime::utcFromTM(TM &tm) const
{
    time_t ret = utcForZone(Pimpl::get(this).spec().c_str(), tm);

    if (tm.tm_isdst)
        ret -= Pimpl::get(this).dstSeconds();

    return ret;
}

