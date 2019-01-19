#include "datetime.ih"

bool DateTime::setYear(int year)
{
                //    s  m  h  md m
    return setTMfields(TM{ 0, 0, 0, 0, 0, year },
        [](TM &dest, TM const &src)
        {
            dest.tm_year = src.tm_year;
        }
    );
}
