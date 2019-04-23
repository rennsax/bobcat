#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf()
:
    d_mode(KEEP_FD)          // comply with old default
{}

