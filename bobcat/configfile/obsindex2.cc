#include "configfile.ih"

size_t ConfigFile::index(const_iterator const &iter) const
{
    return iter->lineNr() - 1;
}

