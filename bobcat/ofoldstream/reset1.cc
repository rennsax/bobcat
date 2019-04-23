#include "ofoldstream.ih"

void OFoldStream::reset(string const &fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldStreambuf::reset(fname);               // = OFilterStreambuf::
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
