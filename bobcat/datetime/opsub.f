template <typename Delta>
inline DateTime operator-(DateTime const &left, Delta const &delta)
{
    return DateTime{ left } -= delta;
}   
