#include "mxstream.ih"

MxStream::Out::~Out()
{
    s_mutex.unlock();
}
