#include "ofdstreambuf.ih"

int OFdStreambuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}
