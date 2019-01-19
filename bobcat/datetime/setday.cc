#include "datetime.ih"

bool DateTime::setDay(int day)
{
    return setTMfields(TM{ 0, 0, 0, day },
        [](TM &dest, TM const &src)
        {
            dest.tm_mday = src.tm_mday;
        }
    );
}
