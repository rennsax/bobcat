inline void OFdStreambuf::reset(int fd, size_t bufSize)
{
    reset(fd, d_mode, bufSize);
}
