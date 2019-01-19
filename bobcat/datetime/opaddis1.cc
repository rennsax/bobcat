#include "datetime.ih"

DateTime &DateTime::operator+=(int seconds)
{
    DateTime tmp{ *this };
    tmp.d_time += seconds;

    return install(tmp);
}

