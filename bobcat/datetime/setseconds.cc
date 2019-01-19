#include "datetime.ih"

bool DateTime::setSeconds(int seconds)
{
    return setTMfields(TM{ seconds },
        [](TM &dest, TM const &src)
        {
            dest.tm_sec = src.tm_sec;
        }
    );
}
