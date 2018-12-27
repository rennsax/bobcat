#include "multistreambuf.ih"

int MultiStreambuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}

