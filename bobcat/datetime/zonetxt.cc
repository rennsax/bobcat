#include "datetime.ih"

// static
string DateTime::zoneTxt(int zoneMinutes)
{
    ostringstream ret;

    if (zoneMinutes < 0)
    {
        ret << '-';
        zoneMinutes = -zoneMinutes;
    }

    ret << setfill('0') << setw(2) << zoneMinutes / 60 << ':' <<
                           setw(2) << zoneMinutes % 30;

    return ret.str();
}
