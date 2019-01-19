#include "datetime.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, DateTime &dt)
{
    DateTime tmp{ in, dt.d_type };
    dt.swap(tmp);

    return in;
}

}   // FBB
