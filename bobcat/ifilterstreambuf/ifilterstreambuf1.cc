#include "ifilterstreambuf.ih"

IFilterStreambuf::IFilterStreambuf(size_t bufSize)
:
    d_maxSize(bufSize < 100 ? 100 : bufSize)
{
    setg(0, 0);                             // underflow is called because
                                            // buffer next == buffer end.
}
