#include "ohexstreambuf.ih"

void OHexStreambuf::setWidth(size_t width)
{
    d_width = width;

    d_widthHandler = 
            d_width == 0 ? 
                    &OHexStreambuf::noWidth 
                : 
                    &OHexStreambuf::widthHandler;
}
