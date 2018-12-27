#include "ofoldstreambuf.ih"

int OFoldStreambuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}



