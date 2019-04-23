#include "ofilterstreambuf.ih"

void OFilterStreambuf::reset(std::ostream &out)
{
    d_out->flush();
    d_dest.close();
    d_out = &out;
}
