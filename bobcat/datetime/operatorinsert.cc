#include "datetime.ih"

// "Wed Jun 30 21:49:08 1993"

namespace FBB
{

std::ostream &operator<<(std::ostream &out, DateTime const &dt)
{
    return out << put_time(dt.displayTM(), "%c");
}

}   // FBB
