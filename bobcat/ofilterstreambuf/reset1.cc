#include "ofilterstreambuf.ih"

void OFilterStreambuf::reset(std::string const &fname, openmode mode)
{
    d_out.flush();
    d_dest.close();
    d_dest.open(fname, mode);
    d_out = &d_dest;
}

