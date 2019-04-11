#include "datetime.ih"

size_t DateTime::weekNr() const
{
    unsigned nr = yearDayNr() / 7;
    return nr == 0 ? 52 : nr;
}
