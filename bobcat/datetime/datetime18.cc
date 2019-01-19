#include "datetime.ih"

DateTime::DateTime(std::string const &timeStr,  int zoneMinutes,
                DSTSpec const &spec)
:                                                   // 20.f
    DateTime( std::istringstream{ timeStr }, zoneMinutes, spec )
{}
