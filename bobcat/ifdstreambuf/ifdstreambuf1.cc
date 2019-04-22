#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf()
:
    EoiBuf(0),
    d_mode(KEEP_FD)          // comply with old default
{}

