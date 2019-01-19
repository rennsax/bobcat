#include "datetime.ih"

bool DateTime::setMinutes(int minutes)
{
    return setTMfields(TM{ 0, minutes },
        [](TM &dest, TM const &src)
        {
            dest.tm_min = src.tm_min;
        }
    );
}
