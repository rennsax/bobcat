template <typename Tp>
MxStream::Out operator<<(MxStream const &mstr, Tp &&tp)
{
    MxStream::Out out{ mstr };
    out << std::forward<Tp>(tp);
    return out;
}
