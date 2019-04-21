#include "ofdstreambuf.ih"

void OFdStreambuf::eoi_()
{
    cleanup(CLOSE_FD);
}
