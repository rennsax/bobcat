#include "datetime.ih"

void DateTime::iniDSTInfoTM(DSTSpec const &spec)
{
    d_dst = DSTInfo::set(this, spec);           // set.cc
    refreshTM();
}
