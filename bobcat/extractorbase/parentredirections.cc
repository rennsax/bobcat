#include "extractorbase.ih"

void ExtractorBase::parentRedirections()
{
    open(d_iChildOutPipe.readOnly(), IFdBuf::CLOSE_FD, d_bufSize);
}
