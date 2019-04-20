#include "ohexstreambuf.ih"

void FBB::OHexStreambuf::clear(bool reset)
{
    if (reset)
    {
        d_separator.clear();
        d_count = 0;
    }
}
