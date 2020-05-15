#include "configfile.ih"

// findKey("key:") - first ws-delimited field following key. initial ws before
//                   key should not be specified: skipped by findKey.

std::string ConfigFile::findKeyTail(string const &key, size_t count) const
{
    static bool called = false;
    deprecated__(called, "findKeyTail(string, size_t)");

    auto iter = obsFind(key, count);
    return iter != end() ? iter->tail() : "";
}

