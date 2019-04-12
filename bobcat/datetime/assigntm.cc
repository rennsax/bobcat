#include "datetime.ih"

    // from utc seconds + current zone to TM
    // use utcFromTM to obtain UTC seconds given zone and spec. in TM
struct tm const &DateTime::assignTM() const
{
    cout << __FILE__": shift = " << zone().zoneShift() << '\n';

    setTZ(zone().spec());
    
    if (not localtime_r(&d_utcSec, &d_tm))
        throw Exception{ 1 } << "can't compute time for " <<
                                zone().spec() << '\n';

    tm2cout(__FILE__" SPEC: ", d_tm);

    resetTZ();

    return d_tm;
}
