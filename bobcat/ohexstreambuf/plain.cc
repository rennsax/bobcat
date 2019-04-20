#include "ohexstreambuf.ih"

void OHexStreambuf::plain(int ch)
{
    out() << setw(2) << ch;
}
