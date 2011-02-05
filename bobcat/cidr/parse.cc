#include "cidr.ih"

Cidr::MaskPair Cidr::parse(string const &cidr)
{
    MaskPair ret {dotted2binary(cidr), 32};

    size_t pos = cidr.find_first_of('/');
    if (pos != string::npos)
    {
        ret.second = A2x(cidr.substr(pos + 1));
        if (A2x::lastFail())
            throw Errno(1, "Cidr: ") << "invalid CIDR: `" << cidr << '\'';
        ret.first = ret.first >> (32 - ret.second) << (32 - ret.second);
    }

    return ret;   
}
