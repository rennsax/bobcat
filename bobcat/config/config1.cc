#include "config.ih"

CF_Pimpl::CF_Pimpl(Casing sType, Comment cType)
:
    d_rmComment(cType == NoComment)
{
    setCasing(sType);
}

Config::Config(Casing sType, Comment cType)
:
    d_ptr(new CF_Pimpl(sType, cType))
{}

