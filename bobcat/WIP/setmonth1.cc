#include "datetime.ih"

bool DateTime::setMonth(Month month, Relative where)
try
{
    DateTime tmp{ *this };
    
    switch (where)
    {
        case NEXT:
                        // E.g., month == MAY, currently SEP: next year
                        //       month == SEP, currently SEP: next year
            if (static_cast<int>(month) <= d_tm.tm_mon)
                ++tmp.d_tm.tm_year;
        break;

        case LAST:
                        // E.g., month == OCT, currently SEP: previous year
                        //       month == SEP, currently SEP: previous year
            if (static_cast<int>(month) >= d_tm.tm_mon)
                --tmp.d_tm.tm_year;
        break;

        case THIS_YEAR:
        break;

        default:
        return false;
    }
    
    tmp.d_tm.tm_mon = month;
    
    tmp.updateTM();
    swap(tmp);
    return true;
}
catch (...)
{
    return false;
}

