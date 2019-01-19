#include "datetime.ih"

bool DateTime::setHours(int hours)
{
    return setTMfields(TM{ 0, 0, hours },
        [](TM &dest, TM const &src)
        {
            dest.tm_hour = src.tm_hour;
        }
    );
}
