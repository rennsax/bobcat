#include "ohexstreambuf.ih"

int OHexStreambuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}
