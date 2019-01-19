#include "datetime.ih"

bool DateTime::setMonth(Month month)
{
                //    s  m  h  md
    return setTMfields(TM{ 0, 0, 0, 0, month },
        [](TM &dest, TM const &src)
        {
            dest.tm_mon = src.tm_mon;
        }
    );
}
