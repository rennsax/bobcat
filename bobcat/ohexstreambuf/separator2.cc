#include "ohexstreambuf.ih"

void OHexStreambuf::separator(string const &sep, bool reset)
{
    d_separator = sep;
    d_separated = &OHexStreambuf::separated;
    clear(reset);
}
