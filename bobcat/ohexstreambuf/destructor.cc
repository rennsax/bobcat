#include "ohexstreambuf.ih"

OHexStreambuf::~OHexStreambuf()
{
    eoi_();
    out().fill(d_padding);
    out().flags(d_current);
}
