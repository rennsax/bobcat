template <typename Ret>
MxStream::Out operator<<(MxStream const &mstr, Ret &(*manip)(Ret &os))
{
    MxStream::Out out{ mstr };
    out << manip;
    return out;
}
