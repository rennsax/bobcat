#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE() const
{
    static bool called = false;
    deprecated__(called, "ConfigFile::beginEndRE()");

    return RE_iteratorPair(d_ptr->endRE(), d_ptr->endRE());
}

