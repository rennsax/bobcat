#include "ifdstreambuf.ih"

void IFdStreambuf::reset(int fd, Mode mode, size_t size)
{
    cleanup(mode);

    d_fd = fd;
    
    resize(size == 0 ? 1 : size);

    setg(size, size);
}
