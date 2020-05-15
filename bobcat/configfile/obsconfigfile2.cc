#include "configfile.ih"

ConfigFile::ConfigFile(string const &fname, Comment cType, Casing sType, 
                       Indices)
:
    ConfigFile(fname, cType, sType)
{
    static bool called = false;
    deprecated__(called, 
            "ConfigFile::ConfigFile(string, Comment, Casing, Indices)");
}


