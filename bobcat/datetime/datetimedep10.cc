#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZone, int)
{
    throw Exception{ 1 } << "DateTime(string, int, int) is obsolete: use "
                            "DateTime(string, int)";
}

