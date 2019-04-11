#include "datetime.ih"

void DateTime::iniPimplTM(DSTSpec const &spec)
{
    d_dst = Pimpl::set(this, spec);           // set.cc
    refreshTM();
}
