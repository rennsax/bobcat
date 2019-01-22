#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int)
{
    throw Exception{ 1 } << "DateTime(string, TimeType, int) is obsolete: use "
                            "DateTime(string, TimeType)";
}
