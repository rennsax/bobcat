#include "ohexstreambuf.ih"

#include <iostream>

void OHexStreambuf::eoi_()
{
    sync();
    separator();
    setWidth(0);
}
