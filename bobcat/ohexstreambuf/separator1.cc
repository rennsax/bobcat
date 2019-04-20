#include "ohexstreambuf.ih"

void OHexStreambuf::separator(bool reset)
{
    d_separated = &OHexStreambuf::plain;
    clear(reset);
}
