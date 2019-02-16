#include "mxstream.ih"

MxStream::Out::Out(MxStream const &mstr)
:
    std::ostream(mstr.d_out.rdbuf())
{
    s_mutex.lock();
}
