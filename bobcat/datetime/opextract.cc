#include "datetime.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, FBB::DateTime &dt)
{
    FBB::DateTime tmp{ in, dt.d_type };
    dt.swap(tmp);

    return in;
}

}   // FBB
