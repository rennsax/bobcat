#include "tablebuf.ih"

int TableBuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}
