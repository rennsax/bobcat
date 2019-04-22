#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf(int fd, size_t size)
:
    EoiBuf(0),
    d_mode(KEEP_FD)         // comply with old default
{
    reset(fd, KEEP_FD, size);
}
