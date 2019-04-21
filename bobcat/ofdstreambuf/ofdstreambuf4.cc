#include "ofdstreambuf.ih"

OFdStreambuf::OFdStreambuf(int fd, Mode mode, size_t bufSize)
:
    EoiBuf(0),
    d_mode(mode)
{
    reset(fd, CLOSE_FD, bufSize);
}

