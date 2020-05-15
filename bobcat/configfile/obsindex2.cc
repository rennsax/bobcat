#include "configfile.ih"

size_t ConfigFile::index(const_iterator const &iter) const
{
    static bool called = false;
    deprecated__(called, "ConfigFile::index(const_iter)");

    return iter->lineNr() - 1;
}

