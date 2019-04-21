#include "ofdstreambuf.ih"

OFdStreambuf::OFdStreambuf()
:
    EoiBuf(0),
    d_mode(CLOSE_FD)           // comply with old default
{}

