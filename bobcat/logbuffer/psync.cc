#include "logbuf.ih"

int LogBuffer::pSync()
{
    d_stream->flush();
    return 0;
}
