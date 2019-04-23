#include "ofoldstream.ih"

void OFoldStream::reset(ostream &out, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldStreambuf::reset(out);             // = OFilterStreambuf
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
