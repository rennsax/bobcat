#include "configfile.ih"

size_t ConfigFile::index(size_t idx) const
{
    static bool called = false;
    deprecated__(called, "ConfigFile::index(size_t)");

    return (begin() + idx)->lineNr() - 1;
}

