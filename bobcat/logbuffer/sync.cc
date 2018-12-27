#include "logbuffer.ih"

int LogBuffer::sync()
{
    d_stream->flush();
    return 0;
}
