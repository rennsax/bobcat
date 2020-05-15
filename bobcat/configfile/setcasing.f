inline void CF_Pimpl::setCasing(Casing type)
{
    d_caseSensitive = type == UseCase;
}

inline void ConfigFile::setCasing(Casing type)
{
    d_ptr->setCasing(type);
}

