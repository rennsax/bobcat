#include "ohexstreambuf.ih"

OHexStreambuf::OHexStreambuf(ostream &out, size_t width, 
                             string const &separator) 
:
    OFilterStreambuf(out),
    d_current(out.flags()),
    d_padding(out.fill('0')),
    d_width(width),
    d_count(0),
    d_separator(separator),
    d_separated(separator.empty() ? 
                        &OHexStreambuf::plain
                    :
                        &OHexStreambuf::separated),
    d_widthHandler(d_width == 0 ? 
                        &OHexStreambuf::noWidth 
                    : 
                        &OHexStreambuf::widthHandler)
{
    out << hex;
}

