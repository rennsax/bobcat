#include "iostreambuf.ih"

std::streamsize IOStreambuf::xsputn(char const *buffer, streamsize n)
{
    return d_out->write(buffer, n) ? n : 0;
}
