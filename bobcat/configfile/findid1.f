inline ConfigFile::const_iterator ConfigFile::findID(
                        std::string const &id, const_iterator from) const 
{
    return d_ptr->findID(id, from);
}

inline ConfigFile::const_iterator ConfigFile::findID(
                                             std::string const &id) const
{
    return findID(id, begin());
}
