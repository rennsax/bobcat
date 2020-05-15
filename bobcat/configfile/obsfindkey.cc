#include "configfile.ih"

std::string ConfigFile::findKey(string const &key, size_t count) const
{
    static bool called = false;
    deprecated__(called, "findKey(string, size_t)");

    auto iter = obsFind(key, count);

    return iter != end() ? iter->value() : "";
}

