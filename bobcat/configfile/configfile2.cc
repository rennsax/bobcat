#include "configfile.ih"

CF_Pimpl::CF_Pimpl(string const &fname, Comment cType, Casing sType)
:
    CF_Pimpl(cType, sType)
{
    open(fname);
}


ConfigFile::ConfigFile(string const &fname, Comment cType, 
                       Casing sType)
:
    d_ptr(new CF_Pimpl(fname, cType, sType))
{}


