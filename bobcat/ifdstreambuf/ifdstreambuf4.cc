#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf(int fd, Mode mode, size_t size)
:
    EoiBuf(0),
    d_mode(mode)
{
    reset(fd, KEEP_FD, size);
}
