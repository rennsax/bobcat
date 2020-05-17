inline Config::Config(std::istream  &stream, Casing sType, Comment cType)
:
    d_ptr(new CF_Pimpl(stream, sType, cType))
{}


