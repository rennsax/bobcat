#include "ofdstreambuf.ih"

OFdStreambuf::OFdStreambuf(int fd, Mode mode, size_t size)
:
    d_mode(mode)
{
    reset(fd, CLOSE_FD, size);
}

