#include "ohexstreambuf.ih"

void OHexStreambuf::separated(int ch)
{
    out() << setw(2) << ch << d_separator;
}
