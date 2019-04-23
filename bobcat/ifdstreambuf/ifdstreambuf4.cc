#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf(int fd, Mode mode, size_t size)
:
    d_mode(mode)
{
    reset(fd, KEEP_FD, size);
}
