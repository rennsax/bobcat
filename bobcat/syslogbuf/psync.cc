#include "syslogbuf.ih"

int Syslogbuf::pSync()
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}
