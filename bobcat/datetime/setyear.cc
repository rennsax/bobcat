#include "datetime.ih"

void DateTime::setYear(int year)
{
                //    s  m  h  md m
    setFields(TM{ 0, 0, 0, 0, 0, year }, YEAR);
}
