#include "ofoldstreambuf.ih"

OFoldStreambuf::BufIt OFoldStreambuf::findOFoldStreambuf(streambuf const *buf)
{
    BufIt it = find(s2_buffers.begin(), s2_buffers.end(),
                dynamic_cast<OFoldStreambuf const *>(buf));

    if (it == s2_buffers.end())
        throw Exception{1} <<
                "Illegal cast from std::streambuf to FBB::OFoldStreambuf";

    return it;
}
