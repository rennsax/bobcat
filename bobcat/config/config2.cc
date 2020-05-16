#include "config.ih"

CF_Pimpl::CF_Pimpl(string const &fname, Casing sType, Comment cType)
:
    CF_Pimpl(sType, cType)
{
    open(fname);
}


Config::Config(string const &fname, Casing sType, Comment cType)
:
    d_ptr(new CF_Pimpl(fname, sType, cType))
{}


