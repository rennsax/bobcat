#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile const &rhs)
:
    d_ptr(new CF_Pimpl(*rhs.d_ptr))
{}
