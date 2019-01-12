#include "datetime.ih"

// static
void DateTime::tm2cout(char const *label, TM const &ts)
{
    cout << label << ": " <<
        ",  sec "  << ts.tm_sec     << 
        ",  min "  << ts.tm_min     << 
        ",  hr "   << ts.tm_hour    << 
        ",  mon "  << ts.tm_mon     << 
        ",  year " << ts.tm_year    << 
        ",  DST " <<  ts.tm_isdst   << '\n';
}
