#include "ofdstreambuf.ih"

void OFdStreambuf::reset(int fd, Mode mode, size_t bufSize)
{
    cleanup(mode);

    d_fd = fd;
    resize(bufSize == 0 ? 1 : bufSize);

    setp();
}
