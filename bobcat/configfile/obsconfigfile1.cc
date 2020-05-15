#include "configfile.ih"

ConfigFile::ConfigFile(Comment cType, Casing sType, Indices)
:
    ConfigFile(cType, sType)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::ConfigFile(Comment, Casing, Indices)");
}

