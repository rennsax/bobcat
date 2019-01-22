#include "datetime.ih"

bool DateTime::setTime(time_t utcSeconds)
{
    DateTime tmp{ *this };

    tmp.d_time = utcSeconds;

    return install(tmp);
}
