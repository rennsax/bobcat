#include "datetime.ih"

// UTC time is ::time(0), zone shift is tzShift (in minutes) as seconds

DateTime::DateTime(int tzShift) // minutes
:
    DateTime( ::time(0), tzShift )          // #6
{}



