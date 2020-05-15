#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE(std::string const &re)
                                                                        const
{
    return d_ptr->beginEndRE(re);
}
