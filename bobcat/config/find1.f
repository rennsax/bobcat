inline Config::const_iterator Config::find(string const &needle, 
                                            const_iterator const &from) const
{
    return d_ptr->find(needle, from);
}

inline Config::const_iterator Config::find(string const &needle) const
{
    return find(needle, begin());
}

