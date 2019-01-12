#include "datetime.ih"

DateTime::Parse::Parse(char sign, int minutes)
:
    Parse(minutes)
{
    if (sign == '-')
        tzShift = -tzShift;
}
