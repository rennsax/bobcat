#include "datetime.ih"

DateTime::DateTime(std::string const &timeStr,  int zoneMinutes)
:
    DateTime( std::istringstream{ timeStr }, zoneMinutes, DSTSpec{ false } )
{}                                                              // 20.f
