// UTC time = ::time(0), LOCALTIME time: shift provided by zone()
inline DateTime::DateTime(TimeType type)
:
    DateTime(::time(0), type)           // 6.cc
{}
