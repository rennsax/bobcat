#include "configfile.ih"

CF_Pimpl::CF_Pimpl(Comment cType, Casing sType)
:
    d_rmComment(cType == NoComment)
{
    setCasing(sType);
}

ConfigFile::ConfigFile(Comment cType, Casing sType)
:
    d_ptr(new CF_Pimpl(cType, sType))
{}

