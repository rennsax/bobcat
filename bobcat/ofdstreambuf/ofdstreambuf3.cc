#include "ofdstreambuf.ih"

#include <iostream>

OFdStreambuf::OFdStreambuf(int fd, size_t bufSize)
:
    d_mode(CLOSE_FD)
{
    reset(fd, CLOSE_FD, bufSize);
}

