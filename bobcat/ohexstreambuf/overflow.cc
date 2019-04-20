#include "ohexstreambuf.ih"

// overrides
int OHexStreambuf::overflow(int ch)
{
    (this->*d_separated)(ch);
    (this->*d_widthHandler)();

    return ch;
}

