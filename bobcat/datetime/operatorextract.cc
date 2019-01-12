#include "datetime.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, DateTime &dt)
{
    DateTime tmp{ dt.d_type, in };
    dt.swap(tmp);

    return in;
}

}   // FBB
