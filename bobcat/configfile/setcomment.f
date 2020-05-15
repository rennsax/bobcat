inline void CF_Pimpl::setComment(Comment type)
{
    d_rmComment = type == NoComment;
}

inline void ConfigFile::setComment(Comment type)
{
    d_ptr->setComment(type);
}

