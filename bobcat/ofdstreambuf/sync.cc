#include "ofdstreambuf.ih"

int OFdStreambuf::sync()
{
    if (pptr() > pbase())               // if there are chars in the buffer
    {                                   // then write them to the device
        if (write(d_fd, ucharPtr(buffer()), pptr() - pbase()) < 0)
            std::cerr << "[Warning] OFdStreambuf::sync could not "
                            "write to FD " << d_fd << '\n';

        setp();                         // and reset the stream pointers
    }

    return 0;                           // return OK.
}
