#include "exception.ih"

namespace FBB
{

std::ostream &errnodescr(std::ostream &out)
{
    if (errno != 0)
    {
        char *buffer = new char[Exception::STRERROR_BUFSIZE];

#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
        if (char *cp = strerror_r(errno, buffer, Exception::STRERROR_BUFSIZE))
            out << cp;
#else
        if (strerror_r(errno, buffer, Exception::STRERROR_BUFSIZE) == 0)
            out << buffer;
#endif
        else
        {
            out << "internal error: strerror_r failed with errno = " << errno;
        }

        delete[] buffer;
    }

    return out;
}

} // FBB
