inline ConfigFile::const_iterator ConfigFile::findRE(
                    std::string const &id, const_iterator const &from) const 
{
    return d_ptr->findRE(id, from);
}

inline ConfigFile::const_iterator ConfigFile::findRE(
                                             std::string const &id) const
{
    return findRE(id, begin());
}
