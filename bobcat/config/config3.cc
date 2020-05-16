#include "config.ih"

Config::Config(Config &&tmp)
:
    d_ptr( new CF_Pimpl(move(*tmp.d_ptr) ))
{}
