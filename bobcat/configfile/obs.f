inline ConfigFile::RE_iterator CF_Pimpl::endRE() const
{
    return d_CIvect.end();
}

inline void ConfigFile::setSearchCasing(Casing type)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::setSearchCasing(Casing)");
    setCasing(type);
}

inline void ConfigFile::setCommentHandling(Comment type)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::setCommentHandling(Comment)");
    setComment(type);
}

