#include "datetime.ih"

size_t DateTime::weekNr() const
{
    DateTime jan1{ *this };

    jan1.d_tm.tm_mday = 1;      // look at this year's Jan 1 
    jan1.d_tm.tm_mon = 0;       

    jan1.refreshTM();            // update its tm-fields
    
    int add = jan1.d_tm.tm_wday;// add # days 
    if (add == 0)               // Jan 1 is a Sunday
        add = 7;                // already at the 1st week

    return (d_tm.tm_yday + add) / 7;
}
