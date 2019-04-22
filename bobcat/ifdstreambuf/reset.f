inline void IFdStreambuf::reset(int fd, size_t size)
{
    reset(fd, d_mode, size);
}
