#include "logbuffer.ih"

void LogBuffer::pSync()     // not used, see logbuffer's header file
{
    throw Exception{ 1 } << __FILE__ << ": obsolete, use sync()";
}

