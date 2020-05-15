#include "configfile.ih"

ConfigFile::const_iterator ConfigFile::obsFind(string const &key, 
                                               size_t count) const
{
    auto iter = findKey(key, begin());

    for (size_t idx = 1; idx < count; ++idx)
        iter = findKey(key, ++iter);

    return iter;
}

