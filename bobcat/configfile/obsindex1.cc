#include "configfile.ih"

size_t ConfigFile::index(size_t idx) const
{
    return (begin() + idx)->lineNr() - 1;
}

