#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile &&tmp)
:
    d_ptr( new CF_Pimpl(move(*tmp.d_ptr) ))
{}
