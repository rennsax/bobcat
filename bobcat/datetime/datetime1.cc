#include "datetime.ih"

// UTC time = ::time(0), LOCALTIME time: shift provided by zone()

DateTime::DateTime(TimeType type)
:
    DateTime(::time(0), type)           // #5
{}
