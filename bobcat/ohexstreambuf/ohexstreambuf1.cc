#include "ohexstreambuf.ih"

OHexStreambuf::OHexStreambuf(ostream &out, size_t width, 
                             string const &separator) 
:
    OFilterStreambuf(out),
    d_current(out.flags()),
    d_padding(out.fill('0')),
    d_count(0),
    d_separator(separator),
    d_separated(separator.empty() ? 
                        &OHexStreambuf::plain
                    :
                        &OHexStreambuf::separated)
{
    setWidth(width);
    out << hex;
}

