#include "datetime.ih"

DateTime::Parse::Parse(int minutes)
:
    zone(true),
    tzShift(minutes)
{}
