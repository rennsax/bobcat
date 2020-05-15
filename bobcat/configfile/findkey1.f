inline ConfigFile::const_iterator ConfigFile::findKey(
                        std::string const &id, 
                        const_iterator const &from) const 
{
    return d_ptr->findKey(id, from);
}

inline ConfigFile::const_iterator ConfigFile::findKey(
                                             std::string const &id) const
{
    return findKey(id, begin());
}
