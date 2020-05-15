#include "configfile.ih"

ConfigFile::const_iterator ConfigFile::find(string const &target) const
{
    return find(target, begin());
}
