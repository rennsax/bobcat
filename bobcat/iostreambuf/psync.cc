#include "iostreambuf.ih"

int IOStreambuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}
