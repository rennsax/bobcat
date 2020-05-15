#include "configfile.ih"

ConfigFile &ConfigFile::operator=(ConfigFile &&tmp)
{
    swap(d_ptr, tmp.d_ptr);
    return *this;
}

