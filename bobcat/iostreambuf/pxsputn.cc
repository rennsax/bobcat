#include "iostreambuf.ih"

std::streamsize IOStreambuf::pXsputn(char const *buffer, 
                                           std::streamsize n)
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, handled by xsputn(...)";
}
